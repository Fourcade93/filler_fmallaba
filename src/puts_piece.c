/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:30:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/16 20:03:45 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_put_pos(char **piece, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
		{
			if (piece[i][j] == '*')
			{
				g_pos.my_x = x;
				g_pos.my_y = y;
				if (g_pos.dir == 1)
					return ;
			}
			x++;
		}
		y++;
	}
}

int put_piece_bottom(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || ret_y < y)
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 2;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_top(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || ret_y > y)
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 1;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || (ret_x >= x && ABS(g_mapy - y) > ABS(g_mapy - ret_y)))
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 1;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || (ret_x <= x && ABS(g_mapy - y) < ABS(g_mapy - ret_y)))
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 1;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_top_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || ((ret_x <= x && ret_y >= y)))
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 1;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_bottom_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || (ret_x >= x && ret_y <= y))
				{
					ret_x = x;
					ret_y = y;
				}
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 2;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_bottom_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				ret_x = x;
				ret_y = y;
			}
		}
	}
	if (ret_x != -1)
	{
		g_pos.dir = 2;
		save_put_pos(piece, ret_x, ret_y);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_top_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;

	y = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y <= piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				g_pos.dir = 1;
				save_put_pos(piece, x, y);
				ft_printf("%d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}
