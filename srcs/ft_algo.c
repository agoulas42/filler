/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:27:58 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 17:19:05 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	algo_down_left(t_filler **pv)
{
	int i;
	int j;

	j = 0 - ((*pv)->fig_width);
	while (j < (*pv)->width)
	{
		i = ((*pv)->heigth - 1);
		while (i >= (0 - (*pv)->fig_heigth))
		{
			if (ft_test_pos_figure(pv, i, j) == 1 && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			i--;
		}
		j++;
	}
	return (0);
}

static int	algo_up_rigth(t_filler **pv)
{
	int i;
	int j;

	j = (*pv)->width - 1;
	while (j >= (0 - (*pv)->fig_width))
	{
		i = 0 - (*pv)->fig_heigth;
		while (i < (*pv)->heigth)
		{
			if (ft_test_pos_figure(pv, i, j) == 1 && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			i++;
		}
		j--;
	}
	return (0);
}

static int	algo_down_rigth(t_filler **pv)
{
	int i;
	int j;

	j = (*pv)->width - 1;
	while (j >= (0 - (*pv)->fig_width))
	{
		i = ((*pv)->heigth - 1);
		while (i >= (0 - (*pv)->fig_heigth))
		{
			if (ft_test_pos_figure(pv, i, j) == 1 && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			i--;
		}
		j--;
	}
	return (0);
}

static int	algo_up_left(t_filler **pv)
{
	int i;
	int j;

	j = (0 - (*pv)->fig_width);
	while (j < (*pv)->width)
	{
		i = (0 - (*pv)->fig_heigth);
		while (i < (*pv)->heigth)
		{
			if (ft_test_pos_figure(pv, i, j) == 1 && ft_test_figure(pv, i, j))
			{
				(*pv)->x_final = i;
				(*pv)->y_final = j;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int			ft_algo(t_filler **pv)
{
	int i;

	i = 0;
	if ((*pv)->algo_nb == 0)
		i = (algo_up_left(pv));
	else if ((*pv)->algo_nb == 1)
		i = (algo_down_rigth(pv));
	else if ((*pv)->algo_nb == 2)
		i = (algo_up_rigth(pv));
	else if ((*pv)->algo_nb == 3)
		i = (algo_down_left(pv));
	if (i == 0 && (*pv)->algo_nb != UP_LEFT)
		i = algo_up_left(pv);
	if (i == 0 && (*pv)->algo_nb != UP_RIGTH)
		i = algo_up_rigth(pv);
	if (i == 0 && (*pv)->algo_nb != DOWN_LEFT)
		i = algo_down_left(pv);
	if (i == 0 && (*pv)->algo_nb != DOWN_RIGTH)
		i = algo_down_rigth(pv);
	return (i);
}
