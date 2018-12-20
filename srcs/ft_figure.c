/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:28:59 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/19 17:31:49 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		init_fig(t_filler **p, int x, int y)
{
	int i;

	i = 0;
	if ((*p)->fig != NULL)
		free_fig(p);
	if (x <= 0 || y <= 0 || *p == NULL)
		return (0);
	if (((*p)->fig = (char **)malloc(sizeof(char*) * (x + 1))) == NULL)
		return (0);
	while (i < x)
	{
		if (((*p)->fig[i] = (char*)ft_memalloc(y + 1)) == NULL)
			return (0);
		i++;
	}
	(*p)->fig[i] = NULL;
	(*p)->fig_heigth = x;
	(*p)->fig_width = y;
	return (1);
}

int		gnl_fig(t_filler **p, char **line)
{
	int		u;
	int		x;
	int		res;

	u = 0;
	x = (*p)->fig_heigth;
	while (u < x)
	{
		if ((res = get_next_line((*p)->fd, line)) < 0)
			return (0);
		(*p)->fig[u] = *line;
		u++;
	}
	(*p)->fig[u] = NULL;
	ft_test_formfig(p);
	return (1);
}

int		get_fig(t_filler **p, char **line)
{
	char	**tab;
	int		i;

	free_fig(p);
	tab = NULL;
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	ft_strdel(line);
	if (init_fig(p, ft_atoi(tab[1]), ft_atoi(tab[2])) == 0
			|| gnl_fig(p, line) == 0)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (1);
}
