/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:30:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/21 19:34:13 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_pos(t_pos check_pos)
{
	g_pos.my_x = check_pos.my_x;
	g_pos.my_y = check_pos.my_y;
}

int		check_piece_pos(char **piece, int x, int y, t_pos point)
{
	int i;
	int j;
	int x_start;

	i = -1;
	x_start = x;
	while (piece[++i])
	{
		j = -1;
		x = x_start - 1;
		while (piece[i][++j] && ++x >= 0)
			if (piece[i][j] == '*' &&
				ABS((point.diry - y)) + ABS((point.dirx - x)) <
				ABS((point.diry - point.my_y)) +
				ABS((point.dirx - point.my_x)))
				return (1);
		y++;
	}
	return (0);
}

void	put_pos(char **piece, int x, int y, t_pos *point)
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
		x = x_start - 1;
		while (piece[i][++j] && ++x >= 0)
			if (piece[i][j] == '*' && (!check || (check &&
			ABS(((*point).diry - y)) + ABS(((*point).dirx - x)) <
			ABS(((*point).diry - (*point).my_y)) +
			ABS(((*point).dirx - (*point).my_x)))))
			{
				(*point).my_x = x;
				(*point).my_y = y;
				check = 1;
			}
		y++;
	}
}

int		put_piece(char **map, char **piece, int piece_y, t_pos point)
{
	int		x;
	int		y;
	t_pos	ret;

	y = -1;
	ret.my_x = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			break;
		x = -1;
		while (++x < g_mapx)
			if ((map[y][x] == '.' || map[y][x] == g_i_am) &&
				possible_put_piece(map, piece, x, y))
				if (ret.my_x == -1 || check_piece_pos(piece, x, y, point))
				{
					ret.my_x = x;
					ret.my_y = y;
					put_pos(piece, x, y, &point);
				}
	}
	if (ret.my_x == -1)
		return (0);
	ft_printf("%d %d\n", ret.my_y, ret.my_x);
	return (1);
}
