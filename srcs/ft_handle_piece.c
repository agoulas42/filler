/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:21:53 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 15:22:41 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		ft_test_piece(t_game **p, int x, int y)
{
	int		i;
	int		j;
	int		cpt;
	char	c;
	char	d;

	cpt = 0;
	c = (*p)->myplayer[0];
	d = (*p)->enemy[0];
	i = 0;
	while (cpt <= 1 && i < (*p)->elem_heigth && (i + x) < (*p)->heigth )
	{
		j = 0;
		while (cpt <= 1 && j < (*p)->elem_width && (j + y) < (*p)->width)
		{
			if (x + i >= 0 && y + j >= 0)
			{
				if ((*p)->elem[i][j] == '*' && ((*p)->ring[x + i][ y + j] != '.'))
				{
					if ((*p)->ring[x + i][y + j] == c || (*p)->ring[x + i][y + j] == c + 32)
							cpt++;
					if ((*p)->ring[x + i][y + j] == d || (*p)->ring[x + i][y + j] == d + 32)
						cpt = cpt + 2;
				}
			}
			j++;
		}
		i++;
	}
	if (cpt == 1)
		return (1);
	return (0);
}

int			ft_piece_valide(t_game **p)
{
	int i;
	int j;
	t_point *test;


	
	i = ((*p)->mineh != 0) ? (0 - (*p)->mineh) : 0;
	test = NULL;
	write((*p)->test,"test piece\n", 11);
	while (i < (*p)->heigth)
	{
			j = ((*p)->minew != 0) ? (0 - (*p)->minew) : 0;
			while (j < (*p)->width)
			{
				if (ft_test_piece(p, i, j) == 1)
					ft_add_last(&test, init_point(i, j));
				j++;
			}
		i++;
	}
	if (test != NULL)
	{
		ft_printf("%d %d\n", test->x, test->y);
		write ((*p)->test,ft_itoa(test->x),ft_strlen(ft_itoa(test->x)));
		write ((*p)->test," ", 1);
		write ((*p)->test,ft_itoa(test->y),ft_strlen(ft_itoa(test->y)));
		write((*p)->test,"\n", 1);
		free_piece(p);
		free_ring(p);
		ft_point_delone(test);
		//ft_free_point(p);
		return (1);
	}
	else
		write((*p)->test,"fin test\n", 9);
	return (0);
}
