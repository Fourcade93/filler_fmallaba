/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:39:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/15 20:32:02 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define NAME "fmallaba.filler"

int				g_mapx;
int				g_mapy;

int				get_piece(char ***piece);
int				get_map(char ***map);
void			del_map(char ***map);
int				possible_put_piece(char **map, char **piece, int start_x, int y);
int				put_piece_top_right(char **map, char **piece, int piece_y);
int				put_piece_bottom_left(char **map, char **piece, int piece_y);
int				put_piece_bottom_right(char **map, char **piece, int piece_y);
int				put_piece_top_left(char **map, char **piece, int piece_y);

#endif