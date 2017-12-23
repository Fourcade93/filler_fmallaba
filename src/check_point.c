/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:26:23 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/23 12:00:34 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_corner(char **map, t_pos check, t_pos map_size)
{
	int x;
	int y;

	y = 0;
	x = 0;
	(check.diry == map_size.my_y - 1) ? y = check.diry - 1 : y;
	(check.dirx == map_size.my_x - 1) ? x = check.dirx - 1 : x;
	if (map[y][x] == g_i_am || map[y][x] == g_enemy)
		return (0);
	if (map[y][x + 1] == g_i_am || map[y][x + 1] == g_enemy)
		return (0);
	if (map[y + 1][x] == g_i_am || map[y + 1][x] == g_enemy)
		return (0);
	if (map[y + 1][x + 1] == g_i_am || map[y + 1][x + 1] == g_enemy)
		return (0);
	return (1);
}

int		check_left_right(char **map, t_pos check)
{
	int y;

	y = check.diry;
	if (map[y][check.dirx] == g_i_am || map[y][check.dirx] == g_enemy)
		return (0);
	if (map[y - 1][check.dirx] == g_i_am || map[y - 1][check.dirx] == g_enemy)
		return (0);
	if (map[y - 2][check.dirx] == g_i_am || map[y - 2][check.dirx] == g_enemy)
		return (0);
	if (map[y + 1][check.dirx] == g_i_am || map[y + 1][check.dirx] == g_enemy)
		return (0);
	if (map[y + 2][check.dirx] == g_i_am || map[y + 2][check.dirx] == g_enemy)
		return (0);
	return (1);
}

int		check_top_bottom(char **map, t_pos check)
{
	int x;

	x = check.dirx;
	if (map[check.diry][x] == g_i_am || map[check.diry][x] == g_enemy)
		return (0);
	if (map[check.diry][x - 1] == g_i_am || map[check.diry][x - 1] == g_enemy)
		return (0);
	if (map[check.diry][x - 2] == g_i_am || map[check.diry][x - 2] == g_enemy)
		return (0);
	if (map[check.diry][x + 1] == g_i_am || map[check.diry][x + 1] == g_enemy)
		return (0);
	if (map[check.diry][x + 2] == g_i_am || map[check.diry][x + 2] == g_enemy)
		return (0);
	return (1);
}

int		check_point(char **map, t_pos check, t_pos map_size)
{
	if ((check.dirx == map_size.my_x - 1 || check.dirx == 0) &&
		(check.diry == 0 || check.diry == map_size.my_y - 1))
		return (check_corner(map, check, map_size));
	if (check.diry == map_size.my_y / 2 &&
	(check.dirx == 0 || check.dirx == map_size.my_x - 1))
		return (check_left_right(map, check));
	if (check.dirx == map_size.my_x / 2 &&
	(check.diry == 0 || check.diry == map_size.my_y - 1))
		return (check_top_bottom(map, check));
	return (1);
}
