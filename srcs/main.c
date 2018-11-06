/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:52:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 12:47:58 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int main(void)
{
	t_game	*p;
	char	*line;
	int		i;

	i = 1;
	p = NULL;

	int fd;

	if ((fd = open("test.txt",O_CREAT|O_RDWR)) <= 0)
		return (0);
	line = ft_strnew(1);
	if (init_game(&p) == 0)
		return (0);
	ft_get_header(&p, &line);
	ft_getplayer(&p, &line);
	while (i == 1)
	{
		if (get_next_line(p->fd, &line) == -1)
			break ;
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			get_ring(&p, &line);
			write(p->test,"avant\n",6);
			ft_print_ring(p);
			write(p->test,"\n",1);
		}
		else if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			write(p->test,line,ft_strlen(line));
			write(p->test,"\n",1);
			ft_print_ring(p);
			get_piece(&p, &line);
			if (ft_piece_valide(&p) == 0)
				return (0);
		}
		else
			ft_strdel(&line);
	}
	return (1);
}
