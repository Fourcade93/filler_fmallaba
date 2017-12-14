/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:39:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/14 20:40:11 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define NAME "fmallaba.filler"
# define GOT_X "<got (X):"
# define GOT_O "<got (O):"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

int				g_mapx;
int				g_mapy;

#endif