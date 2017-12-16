/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/16 19:06:15 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "filler_struct.h"

int		get_func_num_help(void)
{
	int	half_gx;
	int	half_gy;

	half_gx = g_mapx / 2;
	half_gy = g_mapy / 2;
	if (g_pos.my_x >= half_gx && g_pos.my_y >= half_gy)
		return (0);
	if (g_pos.my_x < half_gx && g_pos.my_y >= half_gy)
		return (1);
	if (g_pos.my_x >= half_gx && g_pos.my_y < half_gy)
		return (2);
	if (g_pos.my_x < half_gx && g_pos.my_y < half_gy)
		return (3);
	return (0);
}

int		get_func_num(char **map)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < g_mapy)
	{
		x = -1;
		while (++x < g_mapx)
		{
			if (map[y][x] == g_i_am)
			{
				g_pos.my_x = x;
				g_pos.my_y = y;
			}
			if (map[y][x] == g_enemy)
			{
				g_pos.en_x = x;
				g_pos.en_y = y;
			}
		}
	}
	return (get_func_num_help());
}

void	get_enemy_pos_help(int fy, int fx, int sy, int sx)
{
	if (fy == -1)
		return ;
	else if (sy == -1 || (ABS((g_pos.en_x + g_pos.en_y) - (fy + fx)) >
					   ABS((g_pos.en_x + g_pos.en_y) - (sy + sx))))
	{
		g_pos.en_y = fy;
		g_pos.en_x = fx;
	}
	else
	{
		g_pos.en_y = sy;
		g_pos.en_x = sx;
	}
}

void	get_enemy_pos(char **map)
{
	int	x[3];
	int	y[3];

	y[0] = -1;
	y[1] = -1;
	y[2] = -1;
	while (++(y[0]) < g_mapy)
	{
		x[0] = -1;
		while (++(x[0]) < g_mapx)
		{
			if (map[y[0]][x[0]] == 'o' && y[1] == -1)
			{
				y[1] = y[0];
				x[1] = x[0];
			}
			if (map[y[0]][x[0]] == 'o' && y[1] != -1)
			{
				y[2] = y[0];
				x[2] = x[0];
			}
		}
	}
	get_enemy_pos_help(y[1], x[1], y[2], x[2]);
}

int		get_new_func_num(char **map, int func_num)
{
	int	half_gx;
	int	half_gy;

	get_enemy_pos(map);
	half_gx = g_mapx / 2;
	half_gy = g_mapy / 2;
	if (g_pos.en_y < g_pos.my_y && g_pos.en_x < g_pos.my_x &&
	g_pos.my_y <= half_gy)
		return (6);
	if (g_pos.en_y < g_pos.my_y && g_pos.en_x < g_pos.my_x &&
		g_pos.my_y > half_gy)
		return (0);
	if (g_pos.en_y > g_pos.my_y && g_pos.en_x > g_pos.my_x &&
		g_pos.my_y >= half_gy)
		return (7);
	if (g_pos.en_y > g_pos.my_y && g_pos.en_x > g_pos.my_x &&
		g_pos.my_y < half_gy)
		return (3);
	if (g_pos.en_y < g_pos.my_y && g_pos.en_x > g_pos.my_x &&
		g_pos.my_y <= half_gy)
		return (7);
	if (g_pos.en_y < g_pos.my_y && g_pos.en_x > g_pos.my_x &&
		g_pos.my_y > half_gy)
		return (1);
	if (g_pos.en_y > g_pos.my_y && g_pos.en_x < g_pos.my_x &&
		g_pos.my_y >= half_gy)
		return (6);
	if (g_pos.en_y > g_pos.my_y && g_pos.en_x < g_pos.my_x &&
		g_pos.my_y < half_gy)
		return (2);
	return (func_num);
}

int		continue_fill(char **map, char **piece, int func_num)
{
	char	*line;
	int		piece_y;

	del_map(&map);
	get_next_line(0, &line);
	get_next_line(0, &line);
	if (!get_map(&map))
		return (0);
	if (!(piece_y = get_piece(&piece)))
		return (0);
	func_num = get_new_func_num(map, func_num);
	if (!(g_put_funcs[func_num])(map, piece, piece_y))
	{
		del_map(&piece);
		return (0);
	}
	del_map(&piece);
	return (1);
}

void	first_algo(char **map)
{
	char	**piece;
	int		piece_y;
	int		func_num;

	piece_y = get_piece(&piece);
	func_num = get_func_num(map);
	(g_put_funcs[func_num])(map, piece, piece_y);
	del_map(&piece);
	while (continue_fill(map, piece, func_num))
		;
	ft_printf("%d %d\n", 0, 0);
}

void	read_map(void)
{
	char	**map;
	char	*line;

	map = (char**)ft_memalloc(sizeof(char*) * (g_mapy + 1));
	get_next_line(0, &line);
	ft_strdel(&line);
	get_map(&map);
	if (g_i_am == 'O')
		g_enemy = 'X';
	else
		g_enemy = 'O';
	first_algo(map);
}

int		main(void)
{
	char	*line;

	line = NULL;
	g_mapx = 0;
	g_mapy = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "p1") && ft_strstr(line, NAME))
			g_i_am = 'O';
		if (ft_strstr(line, "p2") && ft_strstr(line, NAME))
			g_i_am = 'X';
		if (ft_strstr(line, "Plateau"))
		{
			g_mapy = ft_atoi(ft_strchr(line, ' '));
			g_mapx = ft_atoi(ft_strrchr(line, ' '));
			break ;
		}
	}
	ft_strdel(&line);
	read_map();
	return (0);
}