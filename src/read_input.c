/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/15 16:09:01 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece_size(char **piece, int piece_x, int piece_y)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	y = -1;
	while (++y < piece_y)
	{
		x = -1;
		while (++x < piece_x)
			if (piece[y][x] == '*')
				count++;
	}
	return (count);
}

int		get_piece(char ***piece)
{
	int		piece_x;
	int		piece_y;
	int		i;
	char	*line;

	if (!get_next_line(0, &line))
		return (0);
	piece_y = ft_atoi(ft_strchr(line, ' '));
	piece_x = ft_atoi(ft_strrchr(line, ' '));
	*piece = (char**)ft_memalloc(sizeof(char*) * (piece_y + 1));
	i = -1;
	ft_strdel(&line);
	while (++i < piece_y && get_next_line(0, &line))
		(*piece)[i] = line;
	(*piece)[i] = 0;
	return (piece_y);
}

int		get_map(char ***map)
{
	int		i;
	char	*line;
	
	i = 0;
	while (get_next_line(0, &line))
	{
		(*map)[i++] = ft_strsub(line, 4, g_mapx);
		if (ft_atoi(line) == g_mapy - 1)
			break;
		ft_strdel(&line);
	}
	(*map)[i] = 0;
	ft_strdel(&line);
	if (i < g_mapy)
		return (0);
	return (1);
}

void	del_map(char ***map)
{
	int		i;

	i = -1;
	while ((*map)[++i])
		ft_strdel(&((*map)[i]));
}

int		possible_put_piece(char **map, char **piece, int start_x, int y)
{
	int		i;
	int		j;
	int		x;
	int		check;

	i = -1;
	check = 0;
	while (piece[++i])
	{
		j = -1;
		x = start_x;
		while (piece[i][++j])
		{
			if (x >= g_mapx || (piece[i][j] == '*' && map[y][x] == 'X') ||
			check > 1)
				return (0);
			if (map[y][x] == 'O' && piece[i][j] == '*')
				check++;
			x++;
		}
		y++;
	}
	if (check != 1)
		return (0);
	return (1);
}

int		put_piece(char **map, char **piece, int piece_y)
{
	int		x;
	int		y;

	y = -1;
	while (++y < g_mapy)
	{
		if (g_mapy - y < piece_y)
			return (0);
		x = -1;
		while (++x < g_mapx)
		{
			if ((map[y][x] == '.' || map[y][x] == 'O') &&
			possible_put_piece(map, piece, x, y))
			{
				ft_printf("%d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int		continue_fill(char **map, char **piece)
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
	if (!put_piece(map, piece, piece_y))
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

	piece_y = get_piece(&piece);
	put_piece(map, piece, piece_y);
	del_map(&piece);
	while (continue_fill(map, piece))
		;
}

void	read_map(char i_am)
{
	char	**map;
	char	*line;

	map = (char**)ft_memalloc(sizeof(char*) * (g_mapy + 1));
	get_next_line(0, &line);
	ft_strdel(&line);
	get_map(&map);
	if (i_am == 'O')
		first_algo(map);
	// else
	// 	second_algo(map);
}

int		main(void)
{
	char	*line;
	char	i_am;

	line = NULL;
	g_mapx = 0;
	g_mapy = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "p1") && ft_strstr(line, NAME))
			i_am = 'O';
		if (ft_strstr(line, "p2") && ft_strstr(line, NAME))
			i_am = 'X';
		if (ft_strstr(line, "Plateau"))
		{
			g_mapy = ft_atoi(ft_strchr(line, ' '));
			g_mapx = ft_atoi(ft_strrchr(line, ' '));
			break ;
		}
	}
	ft_strdel(&line);
	read_map(i_am);
	return (0);
}