/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:28:36 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/23 11:59:54 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos	*get_pos_help(int my_x, int my_y, t_pos map_size)
{
	int half_gx;
	int half_gy;

	half_gx = map_size.my_x / 2;
	half_gy = map_size.my_y / 2;
	if (my_x >= half_gx && my_y >= half_gy)
		return (top_left(map_size));
	if (my_x < half_gx && my_y >= half_gy)
		return (top_right(map_size));
	if (my_x >= half_gx && my_y < half_gy)
		return (bottom_left(map_size));
	if (my_x < half_gx && my_y < half_gy)
		return (bottom_right(map_size));
	return (top_left(map_size));
}

t_pos	*get_pos(char **map, t_pos map_size)
{
	int x;
	int y;
	int my_x;
	int my_y;

	y = -1;
	my_x = 0;
	my_y = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == g_i_am)
			{
				my_x = x;
				my_y = y;
				return (get_pos_help(my_x, my_y, map_size));
			}
		}
	}
	return (get_pos_help(my_x, my_y, map_size));
}
