/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:24:26 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 15:29:49 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int			init_ring(t_game **p)
{
	int i;
	int x;
	int y;

	x = (*p)->heigth;
	y = (*p)->width;
	if (((*p)->ring = (char **)malloc(sizeof(char*) * (x + 1))) == NULL)
		return (0);
	i = 0;
	while (i < x)
	{
		if (((*p)->ring[i] = (char*)ft_memalloc(y + 1)) == NULL)
			return (-1);
		i++;
	}
	(*p)->ring[i] = 0;
	return (1);
}

int				free_ring(t_game **p)
{
	int		i;

	i = (*p)->heigth - 1;
	while (i >= 0 && (*p)->ring[i] != NULL)
	{
		free((*p)->ring[i]);
		i--;
	}
	return (1);
}

void			ft_print_ring(t_game *p)
{
	int i;

	write (p->test,"Plateau",7);
	write (p->test,ft_itoa(p->heigth),ft_strlen(ft_itoa(p->heigth)));
	write (p->test," ", 1);
	write (p->test,ft_itoa(p->width),ft_strlen(ft_itoa(p->width)));
	write (p->test,"\n",1);
	i = 0;
	i = 0;
	while (i < p->heigth)
	{
		write (p->test,"*** ", 4);
		write (p->test,p->ring[i],ft_strlen(p->ring[i]));
		write (p->test,"\n",1);
		i++;
	}
}

int			gnl_ring(t_game **p, char **line)
{
	int i;
	int j;
	int u;
	int res;

	u = 0;
	while ((*p)->ring[u] != NULL && (res = get_next_line((*p)->fd, line)) > -1)
	{
		j = ft_find_carac(*line, ' ') + 1;
		i = 0;
		while (i < (int)ft_strlen(*line) && i < (*p)->heigth)
		{
			(*p)->ring[u][i] = (*line)[j + i];
			if ((*p)->ring[u][i] == (*p)->enemy[0] ||
					(*p)->ring[u][i] == (*p)->enemy[1])
				add_pointxy(p, u, i, 2);
			i++;
		}
		(*p)->ring[u][i] = '\0';
		u++;
	}
	if (res == -1)
		return (-1);
	return (1);
}


int				get_ring(t_game **p, char **line)
{
	char	**tab;
;
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	(*p)->heigth = ft_atoi(tab[1]);
	(*p)->width = ft_atoi(tab[2]);
	init_ring(p);
	if (get_next_line((*p)->fd, line) <= -1)
		return (0);
	if (gnl_ring(p, line) == -1)
		return (0);
	return (1);
}

