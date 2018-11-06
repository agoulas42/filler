/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:28:59 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 10:50:24 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		init_piece(t_game **p, int x, int y)
{
	int i;

	i = 0;
	if (x <= 0 || y <= 0 || *p == NULL)
		return (0);
	if (((*p)->elem = (char **)malloc(sizeof(char*) * (x + 1)))== NULL)
		return (0);
	while (i < x)
	{
		if (((*p)->elem[i] = (char*)ft_memalloc(y + 1))== NULL)
			return (0);
		i++;
	}
	(*p)->elem[i] = NULL;
	(*p)->elem_heigth = x;
	(*p)->elem_width = y;
	return (1);
}



int		ft_free_piece(char **p, int length)
{
	int i;

	i = length;
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	return (1);
}

int		gnl_piece(t_game **p, char **line)
{
	int		i;
	int		u;
	int		x;
	int		res;

	u = 0;
	x = (*p)->elem_heigth;
	write((*p)->test,"start piece\n", 12);
	while (u < x)
	{
		if ((res = get_next_line((*p)->fd, line)) < 0)
			return (0);
		i = 0;
		while ((*line)[i] && i < (*p)->elem_width)
		{
			(*p)->elem[u][i] = (*line)[i];
			i++;
		}
		(*line)[i] = '\0';
		u++;
	}
	(*p)->elem[u] = NULL;
	ft_test_formpiece(p);
	return (1);
}

int		get_piece(t_game **p, char **line)
{
	char **tab;

	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	if (init_piece(p, ft_atoi(tab[1]), ft_atoi(tab[2])) == 0
			|| gnl_piece(p, line) == 0)
		return (0);
	return (1);
}
