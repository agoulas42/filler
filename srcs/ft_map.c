/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:24:26 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/19 18:56:54 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	init_map(t_filler **p, int x, int y)
{
	(*p)->heigth = x;
	(*p)->width = y;
	free_map(p);
	if (((*p)->map = (char **)malloc(sizeof(char*) * (x + 1))) == NULL)
		return (0);
	(*p)->i = 0;
	while ((*p)->i < (*p)->heigth)
	{
		if (((*p)->map[(*p)->i] = (char*)ft_memalloc(y + 1)) == NULL)
			return (-1);
		(*p)->i++;
	}
	(*p)->map[(*p)->i] = 0;
	return (1);
}

void		free_map(t_filler **p)
{
	if ((*p)->map != NULL)
	{
		ft_free_tab(&((*p)->map));
		free((*p)->map);
		(*p)->map = NULL;
	}
}

static int	gnl_map(t_filler **p, char **line)
{
	int j;
	int u;
	int res;

	u = 0;
	while (u < (*p)->heigth && (res = get_next_line((*p)->fd, line)) > -1)
	{
		j = ft_find_carac(*line, ' ') + 1;
		(*p)->map[u] = ft_strdup(*line + j);
		ft_strdel(line);
		u++;
	}
	if (res == -1)
		return (-1);
	return (1);
}

int			get_map(t_filler **p, char **line)
{
	char	**tab;
	int		i;

	free_map(p);
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	init_map(p, ft_atoi(tab[1]), ft_atoi(tab[2]));
	ft_strdel(line);
	if (get_next_line((*p)->fd, line) <= -1)
		return (0);
	ft_strdel(line);
	if (gnl_map(p, line) == -1)
		return (0);
	ft_strdel(line);
	i = 0;
	ft_free_tab(&tab);
	free(tab);
	tab = NULL;
	return (1);
}
