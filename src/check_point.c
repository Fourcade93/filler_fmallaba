/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:26:23 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 21:28:04 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int check_corner(char **map, t_pos check)
{
	int x;
	int y;

	y = 0;
	x = 0;
	(check.diry == g_mapy - 1) ? y = check.diry - 1 : y;
	(check.dirx == g_mapx - 1) ? x = check.dirx - 1 : x;
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

int check_left_right(char **map, t_pos check)
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

int check_top_bottom(char **map, t_pos check)
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

int check_point(char **map, t_pos check)
{
	if ((check.dirx == g_mapx - 1 || check.dirx == 0) &&
		(check.diry == 0 || check.diry == g_mapy - 1))
		return (check_corner(map, check));
	if (check.diry == g_mapy / 2 && (check.dirx == 0 || check.dirx == g_mapx - 1))
		return (check_left_right(map, check));
	if (check.dirx == g_mapx / 2 && (check.diry == 0 || check.diry == g_mapy - 1))
		return (check_top_bottom(map, check));
	return (1);
}
