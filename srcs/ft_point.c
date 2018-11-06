/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:39:25 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 12:05:54 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"


t_point		*init_point(int x, int y)
{
	t_point *p;

	p = NULL;
	if ((p = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	p->x = x;
	p->y = y;
	p->next = NULL;
	return (p);
}


void		add_pointxy(t_game **p, int x, int y, int nlist)
{
	t_point *d;

	d = NULL;
	if ((d = init_point(x , y)) != NULL)
	{
		if (nlist == 1)
			ft_add_last(&(*p)->one, d);
		else
			ft_add_last(&(*p)->two, d);
	}
}

void	ft_add_last(t_point **alst, t_point *n)
{
	t_point *cur;

	if (alst && n)
	{
		if (*alst == NULL)
		{
			(*alst) = n;
			(*alst)->next = NULL;
		}
		else
		{
			cur = *alst;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = n;
		}
	}
}

void ft_point_delone(t_point *curr)
{
	if (curr != NULL)
	{
		 if ((curr)->next != NULL)
			ft_point_delone((curr)->next);
		free(curr);
	}
}

void	ft_free_point(t_game **p)
{
	ft_point_delone((*p)->one);
	ft_point_delone((*p)->two);
}
