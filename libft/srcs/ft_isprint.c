/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:45:40 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:01:09 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}
