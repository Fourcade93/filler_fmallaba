/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:39:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/18 17:09:05 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define ABS(x) (x < 0) ? -x : x
# define NAME "fmallaba.filler"

typedef int	(*t_func)();

typedef struct	s_pos
{
	int			my_x;
	int			my_y;
	int			dir;
}				t_pos;

int				g_mapx;
int				g_mapy;
char			g_enemy;
char			g_i_am;
t_pos			g_pos;

int				get_piece(char ***piece);
int				get_map(char ***map);
void			del_map(char ***map);
int				possible_put_piece(char **map, char **piece,
															int start_x, int y);
int				put_piece_top_right(char **map, char **piece, int piece_y);
int				put_piece_bottom_left(char **map, char **piece, int piece_y);
int				put_piece_bottom_right(char **map, char **piece, int piece_y);
int				put_piece_top_left(char **map, char **piece, int piece_y);
int				put_piece_left(char **map, char **piece, int piece_y);
int				put_piece_right(char **map, char **piece, int piece_y);
int				put_bottom_piece(char **map, char **piece, int piece_y);

#endif
