/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:32:36 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/18 18:34:51 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *p;

	p = NULL;
	if (size > 0)
	{
		p = (char *)malloc(sizeof(p) * (size) + 1);
		if (!p)
			return (NULL);
		else
			ft_bzero(p, (size));
	}
	return ((void*)p);
}
