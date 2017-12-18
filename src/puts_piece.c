/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:30:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/18 17:54:09 by fmallaba         ###   ########.fr       */
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

void	save_pos(t_pos check_pos)
{
	g_pos.my_x = check_pos.my_x;
	g_pos.my_y = check_pos.my_y;
}

int check_piece_right(char **piece, int x, int y, t_pos check_pos)
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
				x > check_pos.my_x)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void put_right_pos(char **piece, int x, int y, t_pos *check_pos)
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
			if (piece[i][j] == '*' && (!check || (check && (*check_pos).my_x < x)))
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

int check_piece_top_right(char **piece, int x, int y, t_pos check_pos)
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
				x > check_pos.my_x && y <= g_mapy / 3)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void put_top_right_pos(char **piece, int x, int y, t_pos *check_pos)
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
			if (piece[i][j] == '*' && (!check || (check && (*check_pos).my_x < x && y <= g_mapy / 3)))
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

int check_piece_bottom_left(char **piece, int x, int y, t_pos check_pos)
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
				x <= check_pos.my_x + 2 && y >= check_pos.my_y)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void put_bottom_left_pos(char **piece, int x, int y, t_pos *check_pos)
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
			if (piece[i][j] == '*' && (!check || (check && (*check_pos).my_x > x && (*check_pos).my_y <= y)))
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

void put_bottom_pos(char **piece, int x, int y, t_pos *check_pos)
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
			if (piece[i][j] == '*' && (!check || (check && (*check_pos).my_y < y)))
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

int		check_piece_left(char **piece, int x, int y, t_pos check_pos)
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
				x < check_pos.my_x)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_left_pos(char **piece, int x, int y, t_pos *check_pos)
{
	int	i;
	int	j;
	int	check;
	int	x_start;

	i = -1;
	x_start = x;
	check = 0;
	while (piece[++i])
	{
		j = -1;
		x = x_start;
		while (piece[i][++j])
		{
			if (piece[i][j] == '*' && (!check || (check && (*check_pos).my_x > x)))
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

int put_piece_left(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	t_pos	check_pos;
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
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
				if (ret_x == -1 || check_piece_left(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_left_pos(piece, x, y, &check_pos);
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
				if (ret_x == -1 || check_piece_right(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_right_pos(piece, x, y, &check_pos);
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
				if (ret_x == -1 || check_piece_top_right(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_top_right_pos(piece, x, y, &check_pos);
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
				if (ret_x == -1 || check_piece_bottom_left(piece, x, y, check_pos))
				{
					ret_x = x;
					ret_y = y;
					put_bottom_left_pos(piece, x, y, &check_pos);
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
	int ret_x;
	int ret_y;

	y = -1;
	ret_x = -1;
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
		if (g_mapy - y < piece_y)
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

int	put_bottom_piece(char **map, char **piece, int piece_y)
{
	int x;
	int y;
	int ret_x;
	t_pos	check_pos;
	int ret_y;

	y = -1;
	ret_x = -1;
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
				if (ret_x == -1 || y > ret_y)
				{
					ret_x = x;
					ret_y = y;
					put_bottom_pos(piece, x, y, &check_pos);
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
