/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:28:59 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/24 19:21:04 by agoulas          ###   ########.fr       */
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
		(*p)->fig[u] = ft_strdup(*line);
		ft_strdel(line);
		u++;
	}
	(*p)->fig[u] = NULL;
	ft_test_formfig(p);
	return (1);
}

int		get_fig(t_filler **p, char **line)
{
	char	**tab;

	tab = NULL;
	free_fig(p);
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	ft_strdel(line);
	if (init_fig(p, ft_atoi(tab[1]), ft_atoi(tab[2])) == 0
			|| gnl_fig(p, line) == 0)
		return (0);
	ft_free_tab(&tab);
	tab = NULL;
	return (1);
}
