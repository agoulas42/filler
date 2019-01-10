/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:57:39 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/09 18:26:44 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		ft_test_algo_ybis2(t_filler **p)
{
	if (((*p)->en->mid_y > (*p)->pl->mid_y
		&& (*p)->pl->y_max != ((*p)->width - 1))
		|| ((*p)->en->y_max != ((*p)->width - 1) && (*p)->pl->y_min == 0))
		return (1);
	else if (((*p)->en->mid_y < (*p)->pl->mid_y && (*p)->pl->y_min != 0)
		|| ((*p)->pl->y_max == ((*p)->width - 1) && (*p)->en->y_min != 0))
		return (0);
	else if (((*p)->pl->y_max < (*p)->width - 1))
		return (1);
	else
		return (0);
}

int		ft_test_algo_ybis(t_filler **p)
{
	if ((*p)->pl->mid_y < (((*p)->width - 1) / 2))
	{
		if (((*p)->en->mid_y < (*p)->pl->mid_y && (*p)->pl->y_min != 0)
			|| ((*p)->pl->y_max == ((*p)->width - 1) && (*p)->en->y_min != 0))
			return (0);
		else if (((*p)->en->mid_y > (*p)->pl->mid_y
				&& (*p)->pl->y_max != ((*p)->width - 1))
			|| ((*p)->en->y_max != ((*p)->width - 1) && (*p)->pl->y_min == 0))
			return (1);
		else if ((*p)->pl->y_min > 0)
			return (0);
		else
			return (1);
	}
	else
		return (ft_test_algo_ybis2(p));
}

int		ft_test_algo_bis(t_filler **p, int h)
{
	if (h == 1)
	{
		if (ft_test_algo_ybis(p) == 0)
			(*p)->algo_nb = UP_LEFT;
		else
			(*p)->algo_nb = UP_RIGTH;
	}
	else
	{
		if (ft_test_algo_ybis(p) == 0)
			(*p)->algo_nb = DOWN_LEFT;
		else
			(*p)->algo_nb = DOWN_RIGTH;
	}
	return (0);
}

void	ft_test_algo(t_filler **p)
{
	if (((*p)->en->mid_x < (*p)->pl->mid_x && ((*p)->pl->x_min != 0))
			|| ((*p)->pl->x_max == ((*p)->heigth - 1) && (*p)->en->x_min != 0))
		ft_test_algo_bis(p, 1);
	else if (((*p)->en->mid_x > (*p)->pl->mid_x
				&& (*p)->pl->x_max != ((*p)->heigth - 1))
			|| ((*p)->en->x_max != ((*p)->heigth - 1) && (*p)->pl->x_min == 0))
		ft_test_algo_bis(p, 0);
	else if ((*p)->pl->x_min > 0)
		ft_test_algo_bis(p, 1);
	else
		ft_test_algo_bis(p, 0);
}

void	ft_test_algo2(t_filler **p)
{
	if ((*p)->pl->mid_x < (((*p)->heigth - 1) / 2))
		ft_test_algo(p);
	else
	{
		if (((*p)->en->mid_x > (*p)->pl->mid_x
			&& (*p)->pl->x_max != ((*p)->heigth - 1))
			|| ((*p)->en->x_max != ((*p)->heigth - 1) && (*p)->pl->x_min == 0))
			ft_test_algo_bis(p, 0);
		if (((*p)->en->mid_x < (*p)->pl->mid_x && (*p)->pl->x_min != 0)
			|| ((*p)->pl->x_max == ((*p)->heigth - 1) && (*p)->en->x_min != 0))
			ft_test_algo_bis(p, 1);
		else if ((*p)->pl->x_max != ((*p)->heigth - 1))
			ft_test_algo_bis(p, 0);
		else
			ft_test_algo_bis(p, 1);
	}
}
