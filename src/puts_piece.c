/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:30:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/21 15:31:25 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_pos(t_pos check_pos)
{
	g_pos.my_x = check_pos.my_x;
	g_pos.my_y = check_pos.my_y;
}

int check_piece_pos(char **piece, int x, int y, t_pos check_pos)
{
	int i;
	int j;
	int x_start;

	i = -1;
	x_start = x;
	while (piece[++i])
	{
		j = -1;
		x = x_start;
		while (piece[i][++j])
		{
			if (piece[i][j] == '*' &&
				ABS((check_pos.diry - y)) + ABS((check_pos.dirx - x)) <
					ABS((check_pos.diry - check_pos.my_y)) + ABS((check_pos.dirx - check_pos.my_x)))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void put_pos(char **piece, int x, int y, t_pos *check_pos)
{
	int i;
	int j;
	int check;
	int x_start;

	i = -1;
	x_start = x;
	check = 0;
	while (piece[++i])
	{
		j = -1;
		x = x_start;
		while (piece[i][++j])
		{
			if (piece[i][j] == '*' && (!check || (check &&
			ABS(((*check_pos).diry - y)) + ABS(((*check_pos).dirx - x)) <
			ABS(((*check_pos).diry - (*check_pos).my_y)) + ABS(((*check_pos).dirx - (*check_pos).my_x)))))
			{
				(*check_pos).my_x = x;
				(*check_pos).my_y = y;
				check = 1;
			}
			x++;
		}
		y++;
	}
}

// int	put_piece_all(char **map, char **piece, int piece_y, t_pos check_pos)
// {
// 	int x;
// 	int y;
// 	int ret_x;
// 	int ret_y;

// 	y = -1;
// 	ret_x = -1;
// 	while (++y < g_mapy)
// 	{
// 		if (g_mapy - y < piece_y)
// 			break;
// 		x = -1;
// 		while (++x < g_mapx)
// 		{
// 			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
// 				possible_put_piece(map, piece, x, y))
// 			{
// 				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
// 				{
// 					ret_x = x;
// 					ret_y = y;
// 					put_pos(piece, x, y, &check_pos);
// 				}
// 			}
// 		}
// 	}
// 	if (ret_x != -1)
// 	{
// 		save_pos(check_pos);
// 		ft_printf("%d %d\n", ret_y, ret_x);
// 		return (1);
// 	}
// 	return (0);
// }

int put_piece_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos	check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = g_mapy / 2;
	check_pos.dirx = 0;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = g_mapy / 2;
	check_pos.dirx = g_mapx;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_top_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos	check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = 0;
	check_pos.dirx = g_mapx;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_bottom_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos	check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = g_mapy;
	check_pos.dirx = 0;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_bottom_right(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = g_mapy;
	check_pos.dirx = g_mapx;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_piece_top_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = 0;
	check_pos.dirx = 0;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int put_top_piece(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	t_pos check_pos;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = 0;
	check_pos.dirx = g_mapx / 2;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}

int	put_bottom_piece(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	t_pos	check_pos;
	int ret_y;

	y = -1;
	ret_x = -1;
	check_pos.diry = g_mapy;
	check_pos.dirx = g_mapx / 2 - 5;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
			{
				if (ret_x == -1 || check_piece_pos(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_pos(piece, x, y, &check_pos);
				}
			}
		}
	}
	if (ret_x != -1)
	{
		save_pos(check_pos);
		ft_printf("%d %d\n", ret_y, ret_x);
		return (1);
	}
	return (0);
}
