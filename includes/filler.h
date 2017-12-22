/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:39:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 13:53:42 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define ABS(x) ((x < 0) ? -x : x)
# define NAME "fmallaba.filler"

typedef int	(*t_func)();

typedef struct	s_pos
{
	int			my_x;
	int			my_y;
	int			diry;
	int			dirx;
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
int				put_piece(char **map, char **piece, int piece_y, t_pos point);
t_pos			*top_left(void);
t_pos			*top_right(void);
t_pos			*bottom_left(void);
t_pos			*bottom_right(void);

int				check_piece(char **piece);

#endif
