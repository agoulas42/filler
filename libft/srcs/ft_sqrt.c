/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:46:45 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/05 17:02:46 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <unistd.h>

int ft_sqrt(int nb)
{
	 int i;
	  int sq;

	i = 1;
	sq = 1;
	if (nb == 0)
		return(0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return(0);
}
