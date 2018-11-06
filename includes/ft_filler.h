/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:02:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/11/06 12:08:51 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"

typedef struct	s_p
{
	int			x;
	int			y;
	struct s_p	*next;
}				t_point;


typedef struct	s_game{

	int			fd;
	int			test;
	char		*myplayer;
	char		*enemy;
	int			heigth;
	int			width;
	char		**ring;
	t_point		*one;
	t_point		*two;
	char		**elem;
	int			elem_width;
	int			elem_heigth;
	int			mineh;
	int			maxeh;
	int			minew;
	int			maxew;
	int			x_final;
	int			y_final;
}				t_game;

int				init_player(t_game **p);
int				ft_getplayer(t_game **p, char **line);

int				init_game(t_game **p);
int				ft_get_header(t_game **p, char **line);
int				ft_find_carac(const char *hay, char c);

int				init_ring(t_game **p);
int				gnl_ring(t_game **p, char **line);
int				get_ring(t_game **p, char **line);
void			ft_print_ring(t_game *p);
int				free_ring(t_game **p);

int				init_piece(t_game **p, int x, int y);
int				free_piece(t_game **p);
int				get_piece(t_game **p, char **line);
int				ft_piece_valide(t_game **p);
int				ft_free_piece(char **p, int length);
void			ft_width_p(t_game **p);
void			ft_heigth_p(t_game **p);
void			ft_new_piece(t_game **p);
int				ft_test_formpiece(t_game **p);
void			add_point(t_list **p, t_point **a);
t_point			*init_point(int x,int y);
void			set_point(t_point **p, int x, int y);
void			add_pointxy(t_game **p,int x, int y,int nlist);
void			ft_point_delone(t_point *curr);
void			ft_free_point(t_game **p);
void			ft_add_last(t_point **alst,t_point *n);
int				ft_find_last(const char *hay, char c);
#endif
