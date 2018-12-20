/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:57:39 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/12 19:57:37 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int		testposplay_h(t_filler *p)
{
	if (p->pl->x_min == 0 && p ->pl->x_max == (p->heigth -1))
		return (1);
	return (0);
}

static int		ft_test_algo(t_filler **p)
{
	if (testposplay_h(*p) == 0)
	{
		if ((*p)->pl->x_min != 0 || (*p)->en->mid_x < (*p)->pl->mid_x)
		{
			if ((*p)->en->mid_y <= (*p)->pl->mid_y && (*p)->en->y_max < (*p)->pl->y_max)
				(*p)->algo_nb = UP_LEFT;
			else
				(*p)->algo_nb = UP_RIGTH;
			return (1);
		}
		else if ((*p)->pl->x_max != (*p)->heigth -1 || (*p)->en->mid_x > (*p)->pl->mid_x)
		{
			if ((*p)->en->mid_y <= (*p)->pl->mid_y || (*p)->pl->y_min != 0)
				(*p)->algo_nb = DOWN_LEFT;
			else
				(*p)->algo_nb = DOWN_RIGTH;
			return (1);
		}
		else
			(*p)->algo_nb = UP_LEFT;
	}
	else
	{
		if ((*p)->en->x_max <= (*p)->pl->x_max)
		{
			if ((*p)->en->mid_y < (*p)->pl->mid_y)
				(*p)->algo_nb = UP_LEFT;
			else
				(*p)->algo_nb = UP_RIGTH;
		}
		else
		{
			if ((*p)->en->mid_y <= (*p)->pl->mid_y)
				(*p)->algo_nb = DOWN_LEFT;
			else
				(*p)->algo_nb = DOWN_RIGTH;
		}
	}
	write((*p)->test,"algo 0\n", 7);
	return (0);
}

void		find_pos_enemy(t_filler **p)
{
	filler_point(p);
	ft_test_algo(p);
}
