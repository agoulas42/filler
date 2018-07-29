/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:52:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/25 18:54:16 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"
#include "../includes/ft_filler.h"

int	init_player(t_player *p)
{
	if ((p = (t_player*)malloc(sizeof(t_player))) == NULL)
		return(0);
	p->name = NULL;
	p->pos_x = -1;
	p->pos_y = -1;
	return (1);
}

int		init_play(t_play **p)
{
	if ((*p = (t_play*)malloc(sizeof(t_play))) == NULL)
		return (0);
	(*p)->actual_player = 0;
	if ((init_player((*p)->one) == 0) || (init_player((*p)->two) == 0))
			return (0);
	if (((*p)->fd = open("test", O_RDONLY)) < 0)
		return (0);
	return (1);
}
#include <stdio.h>

int	ft_get_header(t_play **p)
{
	char *line;
	
	line = NULL;
	while (9999)
	{
		ft_get_next_line((*p)->fd, &line);
		printf("/%s/\n",line);
		if ( ft_strlen(line) == 0)
			return (0);
		if (ft_find_carac(line, '#') == -1)
			return (1);
	}
	return (0);
}

int   ft_get_play2(t_play **map,char **line)
{
	int i;

	if ((i =ft_get_next_line((*map)->fd, line) != 1) ||  ft_strlen(*line) == 0)
	{
		ft_printf("gln probleme\n");
		return(0);
	}
	ft_printf("test i = %i/%s/\n",i, *line);
	if (ft_strncmp(*line, "$$$", 2) == 0 && (*map)->actual_player == 0)
	{
		if (ft_strstr(*line, "p2"))
		{
			ft_getplayer(&((*map)->two->name), *line);
		}
		if (ft_strstr(*line, "p1"))
		{
			 ft_getplayer(&((*map)->two->name), *line);
		}
	}
	ft_strdel(line);
	return (1);
}
int		ft_find_carac(const char *hay, char c)
{
	int i;

	i= 0;
	while (hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_getplayer(char **line, const char *hay)
{
	int i;
	int j;
	char *tmp;

	tmp = NULL;
	i = ft_find_carac(hay,'/');
	j = ft_find_carac(hay,'.');
	if (i == -1 || j == -1)
		return (-1);
	ft_strcpy_from_to(*line, (char*)hay, i + 1, j - i);
	fprintf(stderr,"%s\n",*line);
	return (1);
}

int get_map(t_play **map)
{
	char *line;

	if (ft_get_next_line((*map)->fd, &line) && ft_strlen(line) != 0)
	{
		if (ft_strstr(line ,"Plateau"))
		{
			char **tab;

			tab = ft_strsplit(line,' ');
			if (tab[0] == NULL)
				return (0);
			(*map)->map->heigth = ft_atoi(tab[1]);
			(*map)->map->width = ft_atoi(tab[2]);
			free(*tab);
			if ((tab = (char **)ft_memalloc(sizeof(char*) * (*map)->map->heigth)) == NULL)
				return (-1);
			int i;

			i = 0;
			while (tab[i])
			{
				if ((tab[i] = (char*)ft_memalloc(sizeof(char) *(*map)->map->width))== NULL)
					return (-1);
				tab[i][0] = 'a';
				i++;
			}
			i = 0;
			while (tab[i])
				ft_putstr(tab[i++]);
		}
	return (1);
	}
	else
		return (0);
}

int main(void)
{
	t_play	*p;
	char	*line;
	int		i;
		
	i = -1;
		p = NULL;
	if (init_play(&p) == 0)
	{
		ft_printf("play is no malloc\n");
		ft_printf("player is %d\n",p->actual_player);
		return (0);
	}
	line = NULL;
	i = ft_get_header(&p);
	ft_printf("get_header = %i\n",i);
	i = ft_get_play2(&p, &line);
	ft_printf("get_play = %i\n",i);
	i = get_map(&p);
	ft_printf("get_play = %i\n",i);
	return (1);
}
