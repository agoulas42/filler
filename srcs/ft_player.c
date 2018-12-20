/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:47:34 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/19 18:27:56 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int			ft_getplayer(t_filler **p, char **line)
{
	int i;

	i = 1;
	while (ft_strncmp(*line, "$$$ exec p", 9) != 0 && i >= 0)
	{
		ft_strdel(line);
		i = get_next_line((*p)->fd, line);
	}
	if ((*line)[10] == '1' || (*line)[10] == '2')
	{
		(*p)->myplayer = ((*line)[10] == '1' ? 'O' : 'X');
		(*p)->enemy = ((*line)[10] == '1' ? 'X' : 'O');
		ft_strdel(line);
		return (1);
	}
	ft_strdel(line);
	return (0);
}
