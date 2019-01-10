/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:52:51 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/10 17:32:18 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int			main(void)
{
	t_filler	*p;
	char		*line;

	line = NULL;
	p = NULL;
	if (init_filler(&p, &line) != 0)
	{
		p->x_final = -99;
		p->y_final = -99;
		while (p->end_filler == 1)
		{
			if (get_next_line(p->fd, &line) == -1)
				break ;
			if (ft_strncmp(line, "Plateau ", 8) == 0)
				get_map(&p, &line);
			else if (ft_strncmp(line, "Piece ", 6) == 0 && p->map != NULL)
			{
				if (get_fig(&p, &line) == 0)
					break ;
				p->end_filler = ft_fig_valide(&p);
			}
			else
				ft_strdel(&line);
		}
	}
	final_free(&p);
	return (0);
}
