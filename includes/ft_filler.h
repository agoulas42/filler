/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:02:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/12/19 18:56:06 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"

typedef struct	s_p
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			mid_x;
	int			mid_y;
	char		c;
}				t_point;

typedef enum	s_dir
{
				UP_LEFT = 0,
				DOWN_RIGTH = 1,
				UP_RIGTH = 2,
				DOWN_LEFT = 3,
				NONE = 4,

}				e_dir;

typedef struct	s_filler{

	int			fd;
	int			test;
	e_dir		algo_nb;
	char		myplayer;
	char		enemy;
	int			heigth;
	int			width;
	char		**map;
	char		**fig;
	int			fig_width;
	int			fig_heigth;
	int			mineh;
	int			maxeh;
	int			minew;
	int			maxew;
	int			x_final;
	int			y_final;
	t_point		*pl;
	t_point		*en;
	int			end_filler;
	int			i;
	int			j;
}				t_filler;

t_point			*init_point(char c);
void			free_point(t_point **p);

void			ft_find_width_c(t_filler *p, char c, int *min, int *max);
void			ft_find_heigth_c(t_filler *p, char c, int *min, int *max);

int				init_player(t_filler **p);
int				ft_getplayer(t_filler **p, char **line);

int				init_filler(t_filler **pi, char **line);
void			free_filler(t_filler **p);

int				ft_get_header(t_filler **p, char **line);
int				ft_find_carac(const char *hay, char c);
int				ft_find_last(const char *hay, char c);

int				get_map(t_filler **p, char **line);
void			free_map(t_filler **p);

int				init_fig(t_filler **p, int x, int y);
void			free_fig(t_filler **p);
int				get_fig(t_filler **p, char **line);
int				ft_fig_valide(t_filler **p);

void			ft_free_tab(char ***tab);
void			ft_width_fig(t_filler **p);
void			ft_heigth_fig(t_filler **p);

void			ft_new_fig(t_filler **p);
int				ft_test_formfig(t_filler **p);
int				ft_test_figure(t_filler **p, int x, int y);
int				ft_test_pos_figure(t_filler **p, int x, int y);

t_point			*init_point(char c);
void			filler_point(t_filler **p);
void			free_point(t_point **p);

void			find_pos_enemy(t_filler **p);
int				ft_algo(t_filler **pv);
int				re_test_algo(t_filler **pv);
#endif
