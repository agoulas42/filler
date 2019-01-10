/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:27:58 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 17:18:47 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	algo_left_down(t_filler **pv)
{
	int i;
	int j;

	i = ((*pv)->heigth - 1);
	while (i >= (0 - (*pv)->fig_heigth - 1))
	{
		j = 0 - ((*pv)->fig_width - 1);
		while (j < (*pv)->width)
		{
			if (ft_test_pos_figure(pv, i, j) && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

static int	algo_rigth_up(t_filler **pv)
{
	int i;
	int j;

	i = 0 - ((*pv)->fig_heigth - 1);
	while (i < (*pv)->heigth)
	{
		j = (*pv)->width - 1;
		while (j >= (0 - ((*pv)->fig_width - 1)))
		{
			if (ft_test_pos_figure(pv, i, j) && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

static int	algo_rigth_down(t_filler **pv)
{
	int i;
	int j;

	i = ((*pv)->heigth - 1);
	while (i >= (0 - ((*pv)->fig_heigth - 1)))
	{
		j = (*pv)->width - 1;
		while (j >= (0 - ((*pv)->fig_width) - 1))
		{
			if (ft_test_pos_figure(pv, i, j) && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	algo_left_up(t_filler **pv)
{
	int i;
	int j;

	i = (0 - ((*pv)->fig_heigth - 1));
	while (i < (*pv)->heigth)
	{
		j = (0 - ((*pv)->fig_width - 1));
		while (j < (*pv)->width)
		{
			if (ft_test_pos_figure(pv, i, j) && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_algo2(t_filler **pv)
{
	int i;

	i = 0;
	(*pv)->x_final = 0;
	(*pv)->y_final = 0;
	if ((*pv)->algo_nb == 0)
		i = (algo_left_up(pv));
	else if ((*pv)->algo_nb == 1)
		i = (algo_rigth_down(pv));
	else if ((*pv)->algo_nb == 2)
		i = (algo_rigth_up(pv));
	else if ((*pv)->algo_nb == 3)
		i = (algo_left_down(pv));
	if (i == 0 && (*pv)->algo_nb != UP_LEFT)
		i = algo_left_up(pv);
	if (i == 0 && (*pv)->algo_nb != UP_RIGTH)
		i = algo_rigth_up(pv);
	if (i == 0 && (*pv)->algo_nb != DOWN_LEFT)
		i = algo_left_down(pv);
	if (i == 0 && (*pv)->algo_nb != DOWN_RIGTH)
		i = algo_rigth_down(pv);
	return (i);
}
