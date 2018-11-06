/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:53:16 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 11:31:03 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		init_game(t_game **p)
{
	if ((*p = (t_game*)malloc(sizeof(t_game))) == NULL)
		return (0);
	(*p)->one = NULL;
	(*p)->two = NULL;
	(*p)->fd = 0;
	(*p)->x_final = -1;
	(*p)->y_final = -1;
	(*p)->mineh = -1;
	(*p)->minew = -1;
	(*p)->maxeh = -1;
	(*p)->maxew = -1;
	(*p)->test = open("test.txt",O_CREAT | O_TRUNC | O_RDWR);
	return (1);
}
