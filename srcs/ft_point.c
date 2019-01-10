/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:18:14 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 17:55:22 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

t_point	*init_point(char c)
{
	t_point *p;

	if ((p = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	p->c = c;
	return (p);
}

void	filler_point(t_filler **p)
{
	if ((*p)->en == NULL)
		(*p)->en = init_point((*p)->enemy);
	if ((*p)->pl == NULL)
		(*p)->pl = init_point((*p)->myplayer);
	ft_find_heigth_c(*p, (*p)->en->c, &((*p)->en->x_min), &((*p)->en->x_max));
	ft_find_heigth_c(*p, (*p)->pl->c, &((*p)->pl->x_min), &((*p)->pl->x_max));
	ft_find_width_c(*p, (*p)->en->c, &((*p)->en->y_min), &((*p)->en->y_max));
	ft_find_width_c(*p, (*p)->pl->c, &((*p)->pl->y_min), &((*p)->pl->y_max));
	(*p)->pl->mid_x = (*p)->pl->x_min + (*p)->pl->x_max / 2;
	(*p)->pl->mid_y = (*p)->pl->y_min + (*p)->pl->y_max / 2;
	(*p)->en->mid_x = (*p)->en->x_min + (*p)->en->x_max / 2;
	(*p)->en->mid_y = (*p)->en->y_min + (*p)->en->y_max / 2;
}

void	free_point(t_point **p)
{
	if ((*p) != NULL)
	{
		free(*p);
		(*p) = NULL;
	}
}

void	ft_find_width_c(t_filler *p, char c, int *min, int *max)
{
	int	i;
	int	j;
	int	g;

	*min = ft_find_carac(p->map[0], c);
	*max = ft_find_last(p->map[0], c);
	j = 1;
	while (p->map[j] != NULL && j < p->heigth)
	{
		i = (ft_find_carac(p->map[j], c));
		g = (ft_find_last(p->map[j], c));
		if (*min > i && i != -1)
			*min = i;
		if (*max < g && g != -1)
			*max = g;
		j++;
	}
}

void	ft_find_heigth_c(t_filler *p, char c, int *min, int *max)
{
	int j;

	*min = -1;
	*max = -1;
	j = 0;
	while (p->map[j] != NULL && j < p->heigth)
	{
		if (ft_find_carac(p->map[j], c) != -1)
		{
			if (*min == -1)
				*min = j;
			else
				*max = j;
		}
		j++;
	}
}
