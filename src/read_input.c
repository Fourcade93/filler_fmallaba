/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 13:53:03 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_corner(char **map, t_pos check)
{
	int	x;
	int	y;

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

int		check_point(char **map, t_pos check)
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

t_pos	*get_pos_help(int my_x, int my_y)
{
	int	half_gx;
	int	half_gy;

	half_gx = g_mapx / 2;
	half_gy = g_mapy / 2;
	if (my_x >= half_gx && my_y >= half_gy)
		return (top_left());
	if (my_x < half_gx && my_y >= half_gy)
		return (top_right());
	if (my_x >= half_gx && my_y < half_gy)
		return (bottom_left());
	if (my_x < half_gx && my_y < half_gy)
		return (bottom_right());
	return (top_left());
}

t_pos	*get_pos(char **map)
{
	int	x;
	int	y;
	int	my_x;
	int	my_y;
	
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
				return (get_pos_help(my_x, my_y));
			}
		}
	}
	return (get_pos_help(my_x, my_y));
}

void	continue_fill(char **map, char **piece, t_pos *pos, int piece_y)
{
	int		i;

	i = -1;
	while (pos[++i].dirx != -1)
		while (check_point(map, pos[i]))
		{
			if (!put_piece(map, piece, piece_y, pos[i]))
				return ;
			del_map(&map);
			del_map(&piece);
			get_map(&map);
			piece_y = get_piece(&piece);
		}
	(pos[i]).dirx = g_mapx / 2;
	(pos[i]).diry = g_mapy / 2;
	while (put_piece(map, piece, piece_y, pos[i]))
	{
		del_map(&map);
		del_map(&piece);
		get_map(&map);
		piece_y = get_piece(&piece);
	}
}

void	first_algo(char **map)
{
	char	**piece;
	int		piece_y;
	t_pos	*pos;

	piece_y = get_piece(&piece);
	pos = get_pos(map);
	continue_fill(map, piece, pos, piece_y);
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
	free(map);
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