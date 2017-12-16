/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:34:45 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/16 18:48:02 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_STRUCT_H
# define FILLER_STRUCT_H

# include "filler.h"

t_func	(g_put_funcs[9]) = {
	put_piece_top_left,
	put_piece_top_right,
	put_piece_bottom_left,
	put_piece_bottom_right,
	put_piece_bottom,
	put_piece_top,
	put_piece_left,
	put_piece_right,
	NULL};

#endif