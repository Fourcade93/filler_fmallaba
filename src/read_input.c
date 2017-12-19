/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/19 21:10:40 by fmallaba         ###   ########.fr       */
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
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == g_i_am)
			{
				g_pos.my_x = x;
				g_pos.my_y = y;
			}
		}
	}
	return (get_func_num_help());
}

int		check_left_flang(char **map, char **piece)
{
	int	x;
	int	y;
	int	check_i;

	y = -1;
	check_i = 0;
	while (++y < g_mapy / 3)
		if (check_piece(piece) && map[y][g_mapx / 2] == g_enemy)
			return (1);
	x = -1;
	while (++x < g_mapx - 2)
		if (map[g_mapy - 1][x] == g_i_am)
			return (7);
	x = -1;
	while (++x < g_mapx - 2)
		if (map[g_mapy - g_mapy / 3][x] == g_enemy)
			return (6);
	return (4);
}

int		get_new_func_num(int func_num, char **map, char **piece)
{
	int	half_gy;

	half_gy = g_mapy - (g_mapy / 5);
	if (func_num == 0 && g_pos.my_y <= half_gy)
	{
		if (check_piece(piece))
			return (7);
		return (4);
	}
	if (func_num == 7 || func_num == 4 || func_num == 6)
		return (check_left_flang(map, piece));
	return (func_num);
}

int		continue_fill(char **map, char **piece, int *func_num)
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
	*func_num = get_new_func_num(*func_num, map, piece);
	if (!(g_put_funcs[*func_num])(map, piece, piece_y))
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
	while (continue_fill(map, piece, &func_num))
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