/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:39:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 21:44:06 by fmallaba         ###   ########.fr       */
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

char			g_enemy;
char			g_i_am;

int				get_piece(char ***piece);
int				get_map(char ***map, t_pos map_size);
void			del_map(char ***map);
int				possible_put_piece(char **map, char **piece,
															int start_x, int y);
int				put_piece(char **map, char **piece, int piece_y, t_pos point);
t_pos			*top_left(t_pos map_size);
t_pos			*top_right(t_pos map_size);
t_pos			*bottom_left(t_pos map_size);
t_pos			*bottom_right(t_pos map_size);

int				check_piece(char **piece);
int				check_point(char **map, t_pos check);
t_pos			*get_pos(char **map, t_pos map_size);

#endif
