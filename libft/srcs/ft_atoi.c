/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:04:36 by agoulas           #+#    #+#             */
/*   Updated: 2018/08/20 12:36:35 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int				neg;
	int				i;
	long long int	n;

	neg = 1;
	i = 0;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		str++;
	while (ft_isdigit(str[i]) && str[i])
	{
		n = n * 10 + ((char)str[i] - '0');
		i++;
	}
	return (n * neg);
}
