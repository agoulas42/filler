/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:52:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/20 12:56:42 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int end_game(t_filler **p)
{
	(*p)->x_final = 0;
	(*p)->y_final = 0;
	(*p)->end_filler = 0;
	free_filler(p);
	return (0);
}

int		main(void)
{
	t_filler	*p;
	char		*line;

	line = NULL;
	p = NULL;
	if (init_filler(&p, &line) == 0)
		end_game(&p);
	while (p->end_filler == 1)
	{
		if (get_next_line(p->fd, &line) == -1)
			break ;
		if (ft_strncmp(line, "Plateau ", 8) == 0)
			get_map(&p, &line);
		else if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			get_fig(&p, &line);
			if (ft_fig_valide(&p) == 0)
				end_game(&p);
		}
		else
			ft_strdel(&line);
	}
	ft_printf("%d %d\n", p->x_final, p->y_final);
	write(p->test,ft_itoa(p->x_final), ft_strlen(ft_itoa(p->x_final)));
	write(p->test, " ", 1);
	write(p->test,ft_itoa(p->y_final), ft_strlen(ft_itoa(p->y_final)));
	write(p->test, "\n", 1);
	free(p);
	p = NULL;
	while(1);
	return (0);
}
