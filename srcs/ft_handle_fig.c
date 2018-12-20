/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:21:53 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/10 19:33:07 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		ft_test_pos_figure(t_filler **p, int x, int y)
{
	if (((x + (*p)->mineh) < 0 || (y + (*p)->minew) < 0)
		|| ((x + (*p)->maxeh) >= ((*p)->heigth)
		|| (y + (*p)->maxew) >= ((*p)->width)))
		return (0);
	else
		return (1);
}

int		ft_test_case_p(t_filler *p, int x, int y)
{
	if (p->map[x][y] == '\0' || x >= p->heigth || y >= p->width)
		return (0);
	else if (p->map[x][y] == p->myplayer)
		return (1);
	else if (p->map[x][y] == p->enemy)
		return (2);
	return (0);
}

int		ft_test_figure(t_filler **p, int x, int y)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	i = 0;
	while (cpt <= 1 && i < (*p)->fig_heigth && (i + x) < (*p)->heigth)
	{
		j = 0;
		while (cpt <= 1 && j < (*p)->fig_width && (j + y) < (*p)->width)
		{
			if ((*p)->fig[i][j] == '*' && ((*p)->map[x + i][y + j] != '.'))
				cpt = cpt + ft_test_case_p(*p, x + i, y + j);
			j++;
		}
		i++;
	}
	if (cpt != 1)
		return (0);
	return (1);
}

int		ft_fig_valide(t_filler **p)
{
	find_pos_enemy(p);
	if (ft_algo(p) == 1)
	{
		ft_printf("%d %d\n", (*p)->x_final, (*p)->y_final);
		return (1);
	}
	else
	{
		ft_printf("%d %d\n", (*p)->x_final, (*p)->y_final);
		return (0);
	}
}
