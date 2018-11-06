/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:54:44 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 11:48:46 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int  free_piece(t_game **p)
{
	ft_free_piece((*p)->elem, (*p)->elem_heigth);
	return (1);
}

	void  ft_width_p(t_game **p)
{
	int i;
	int j;
	int g;

	(*p)->minew = (ft_find_carac((*p)->elem[0], '*'))  % (*p)->elem_width;
	(*p)->maxew = (ft_find_last((*p)->elem[0], '*'))  % (*p)->elem_width;
	j = 1;
	while ((*p)->elem[j] != NULL && j< (*p)->elem_heigth)
	{
		i = (ft_find_carac((*p)->elem[j], '*')) % (*p)->elem_width;
		g = (ft_find_last((*p)->elem[j], '*'))  % (*p)->elem_width;
		if ((*p)->minew > i)
			(*p)->minew = i;
		if ((*p)->maxew < g)
			(*p)->maxew = g;
		j++;
	}
}
void ft_heigth_p(t_game **p)
{
	int j;

	(*p)->mineh = -1;
	(*p)->maxeh = -1;
	j = 0;
	while ((*p)->elem[j] != NULL && j < (*p)->elem_heigth)
	{
		if (ft_find_carac((*p)->elem[j], '*') != -1)
		{
			if ((*p)->mineh == -1)
				(*p)->mineh = j;
			else
				(*p)->maxeh = j;
		}
		j++;
	}
}


int  ft_test_formpiece(t_game **p)
{
	ft_heigth_p(p);
	ft_width_p(p);
	return (1);
}
