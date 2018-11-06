/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2018/10/05 16:53:29 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int ft_get_header(t_game **p, char **line)
{
	int res;

	while ((res = get_next_line((*p)->fd, line)) > -1)
	{
		if (res == 0)
			return (0);
		if (ft_strncmp(*line, "#", 1) != 0)
			break ;
	}
	return (1);
}

int  ft_find_carac(const char *hay, char c)
{
	int i;

	i = 0;
	while (hay && hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_last(const char *hay, char c)
{
	int i;

	i = ft_strlen(hay);
	while (i >= 0)
	{
		if (hay[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
int		test_pos_car(t_game *p,int x, int y)
{
	if (x >= 0 && x <= p->heigth && y >= 0 && y <= p->width)
	{
		if ((y < p->width && (p->ring[x][y + 1] == p->myplayer[0]
						|| p->ring[x][y + 1] == p->myplayer[1]) )
				|| (y > 0 && p->ring[x][y - 1] != '.')
				|| (x < p->heigth && p->ring[x + 1][y] != '.')
				|| (x > 0 && p->ring[x - 1][y] == p->myplayer[0]))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		ft_find_max_heigth(t_game **p,int *min_h, int *max_h)
{
	int i;
	int j;

	*min_h = -1;
	*max_h = -1;
	i = 0;
	while (i < (*p)->heigth)
	{
		j = 0;
		while (j < (*p)->width)
		{
			j++;
		}
		i++;
	}
	return (1);
}
