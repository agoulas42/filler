/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:53:16 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 15:48:47 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		init_filler(t_filler **p, char **line)
{
	if ((*p = (t_filler*)malloc(sizeof(t_filler))) == NULL)
		return (0);
	(*p)->map = NULL;
	(*p)->fig = NULL;
	(*p)->fd = 0;
	(*p)->algo_nb = 0;
	(*p)->heigth = -100;
	(*p)->width = -100;
	(*p)->fig_width = -100;
	(*p)->fig_heigth = -100;
	(*p)->x_final = -100;
	(*p)->y_final = -100;
	(*p)->i = -100;
	(*p)->j = -100;
	(*p)->end_filler = 1;
	(*p)->pl = NULL;
	(*p)->en = NULL;
	if (ft_get_header(p, line) == 0 || ft_getplayer(p, line) == 0)
		return (0);
	return (1);
}

void	free_filler(t_filler **p)
{
	free_map(p);
	free_fig(p);
	free_point(&(*p)->en);
	free_point(&(*p)->pl);
}

void	final_free(t_filler **p)
{
	free_filler(p);
	free(*p);
	p = NULL;
}
