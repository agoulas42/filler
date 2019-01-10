/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:21:53 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 18:20:24 by agoulas          ###   ########.fr       */
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
	if (p->map[x][y] == '\0' || x >= p->heigth || y >= p->width 
			|| x < 0 || y < 0)
		return (2);
	else if (p->map[x][y] == p->myplayer || p->map[x][y] == p->myplayer + 32)
		return (1);
	else if (p->map[x][y] == p->enemy || p->map[x][y] == p->enemy + 32)
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
	while (cpt <= 1 && (*p)->fig[i] != NULL && (i + x) < (*p)->heigth)
	{
		j = 0;
		while (cpt <= 1 && (*p)->fig[i][j] != '\0' && (j + y) < (*p)->width)
		{
			if ((x + i) >= 0 && (y + j) >= 0
				&& (*p)->fig[i][j] == '*' && ((*p)->map[x + i][y + j] != '.'))
				cpt = cpt + ft_test_case_p(*p, x + i, y + j);
			j++;
		}
		i++;
	}
	if (cpt == 1)
		return (1);
	return (0);
}

int		ft_fig_valide(t_filler **p)
{
	int i;

	i = 0;
	filler_point(p);
	ft_test_algo2(p);
	if ((i = ft_algo2(p)) == 0)
		i = ft_algo(p);
	ft_printf("%d %d\n", (*p)->x_final, (*p)->y_final);
	return (i);
}
