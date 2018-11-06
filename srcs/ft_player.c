/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:47:34 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 12:43:09 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int			ft_getplayer(t_game **p, char **line)
{
	if (ft_strncmp(*line, "$$$ exec p", 9) != 0)
	{
		while (get_next_line((*p)->fd, line) > -1)
		{
			if (ft_strncmp(*line, "$$$ exec p", 9) == 0)
				break;
		}
	}
	if ((*line)[10] == '1' || (*line)[10] == '2')
	{
		write((*p)->test, *line, ft_strlen(*line));
		write((*p)->test,"\n", 1);
		(*p)->myplayer = ((*line)[10] == '1' ? "Oo" : "Xx");
		(*p)->enemy = ((*line)[10] == '1' ? "Xx" : "Oo");
		return (1);
	}
	return (0);
}
