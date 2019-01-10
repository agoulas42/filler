/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/24 19:20:09 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int		ft_get_header(t_filler **p, char **line)
{
	int res;

	res = 0;
	while ((res = get_next_line((*p)->fd, line)) > -1)
	{
		if (ft_strncmp(*line, "#", 1) != 0)
			break ;
		else
			ft_strdel(line);
	}
	return (1);
}

int		ft_find_carac(const char *hay, char c)
{
	int i;

	i = 0;
	while (hay && hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_last(const char *hay, char c)
{
	int i;

	i = ft_strlen(hay);
	while (i >= 0)
	{
		if (hay[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
