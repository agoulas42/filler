/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:02:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/07/25 17:34:25 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

# define CAR if (actual_player == 1) then { CAR = 'o'} else { CAR = 'x'};

typedef struct	s_map
{
	char		**ring;
	int			heigth;
	int			width;
}				t_map;


typedef struct	s_player
{
	char		*name;
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct	s_piece
{
	char		**tab;
	int			length;
	int			heigth;
}				t_piece;

typedef struct	s_play{

	int			actual_player;
	int			fd;
	t_player	*one;
	t_player	*two;
	t_map		*map;
	t_piece		*elem;
}				t_play;

int				ft_getplayer(char **line, const char *hay);
int				ft_find_carac(const char *hay, char c);
#endif
