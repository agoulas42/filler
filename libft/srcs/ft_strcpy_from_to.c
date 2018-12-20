/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:18:58 by agoulas           #+#    #+#             */
/*   Updated: 2018/08/07 11:37:56 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcpy_from_to(char *dest, char *src, int start, int length)
{
	int i;

	i = 0;
	if (length < 0 || dest == NULL)
		return (NULL);
	if (src != NULL && dest != NULL)
	{
		while (dest[i] && src[i + start] && i < length)
		{
			dest[i] = src[i + start];
			i++;
		}
		return (dest);
	}
	return (dest);
}
