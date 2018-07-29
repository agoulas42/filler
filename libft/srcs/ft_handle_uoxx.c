/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uoxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:08:42 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/30 18:30:08 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_handle_uox(t_format **f, t_conv *p, va_list *ap)
{
	if (p->specifier == 'o' || p->specifier == 'O')
	{
		return (ft_handle_o(f, p, ap));
	}
	else if (p->specifier == 'u' || p->specifier == 'U')
	{
		return (ft_handle_u(f, p, ap));
	}
	else if (p->specifier == 'x' || p->specifier == 'X')
	{
		return (ft_handle_x(f, p, ap));
	}
	else
		return (0);
	return (1);
}
