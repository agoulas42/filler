/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:54:44 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 15:53:25 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	free_fig(t_filler **p)
{
	if ((*p)->fig != NULL)
	{
		ft_free_tab(&((*p)->fig));
		(*p)->fig = NULL;
		(*p)->fig_width = -100;
		(*p)->fig_heigth = -100;
	}
}

void	ft_width_fig(t_filler **p)
{
	int g;

	(*p)->minew = (ft_find_carac((*p)->fig[0], '*')) % (*p)->fig_width;
	(*p)->maxew = (ft_find_last((*p)->fig[0], '*')) % (*p)->fig_width;
	g = 1;
	while (g < (*p)->fig_heigth)
	{
		(*p)->i = (ft_find_carac((*p)->fig[g], '*')) % (*p)->fig_width;
		(*p)->j = (ft_find_last((*p)->fig[g], '*')) % (*p)->fig_width;
		if ((*p)->minew > (*p)->i)
			(*p)->minew = (*p)->i;
		if ((*p)->maxew < (*p)->j)
			(*p)->maxew = (*p)->j;
		g++;
	}
	(*p)->i = -1;
	(*p)->j = -1;
}

void	ft_heigth_fig(t_filler **p)
{
	int j;

	(*p)->mineh = -1;
	(*p)->maxeh = -1;
	j = 0;
	while ((*p)->fig[j] != NULL && j < (*p)->fig_heigth)
	{
		if (ft_find_carac((*p)->fig[j], '*') != -1)
		{
			if ((*p)->mineh == -1)
				(*p)->mineh = j;
			else
				(*p)->maxeh = j;
		}
		j++;
	}
}

int		ft_test_formfig(t_filler **p)
{
	ft_heigth_fig(p);
	ft_width_fig(p);
	return (1);
}
