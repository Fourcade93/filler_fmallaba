/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/14 21:25:05 by fmallaba         ###   ########.fr       */
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

t_coord	*get_coord(char **piece, int piece_x, int piece_y)
{
	int		count;
	int		x;
	int		y;
	int		num;
	t_coord	*p_coord;

	count = get_piece_size(piece, piece_x, piece_y);
	p_coord = (t_coord*)ft_memalloc(sizeof(t_coord) * (count + 1));
	y = -1;
	num = 0;
	while (++y < piece_y)
	{
		x = -1;
		while (++x < piece_x)
			if (piece[y][x] == '*')
			{
				p_coord[num].x = x;
				p_coord[num].y = y;
				num++;
			}
	}
	p_coord[num].x = -1;
	return (p_coord);
}

t_coord	*get_piece(void)
{
	int		piece_x;
	int		piece_y;
	int		i;
	char	**piece;
	char	*line;

	if (!get_next_line(0, &line))
		return (0);
	piece_y = ft_atoi(ft_strchr(line, ' '));
	piece_x = ft_atoi(ft_strrchr(line, ' '));
	piece = (char**)ft_memalloc(sizeof(char*) * (piece_y + 1));
	i = -1;
	ft_strdel(&line);
	while (++i < piece_y && get_next_line(0, &line))
		piece[i] = line;
	return (get_coord(piece, piece_x, piece_y));
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
	ft_strdel(&line);
	if (i < g_mapy)
		return (0);
	return (1);
}

void	del_map(char ***map)
{
	int		i;

	i = -1;
	while (++i < g_mapy)
		ft_strdel(&((*map)[i]));
}

int		possible_put_piece(char **map, t_coord *piece, int x, int y)
{
	int		min_x;
	int		min_y;
	int		i;
	int		check;

	i = 0;
	min_x = x - piece[i].x;
	min_y = y - piece[i].y;
	check = 0;
	(map[y][x] == 'O') ? check++ : check;
	while (piece[++i].x != -1)
	{
		x = min_x + piece[i].x;
		y = min_y + piece[i].y;
		if (x >= g_mapx || y >= g_mapy || map[y][x] == 'X' || map[y][x] == 'x')
			return (0);
		if (map[y][x] == 'O')
			check++;
	}
	if (check != 1)
		return (0);
	return (1);
}

int		put_piece(char **map, t_coord *piece)
{
	int		x;
	int		y;

	y = -1;
	while (++y < g_mapy)
	{
		x = -1;
		while (++x < g_mapx)
			if ((map[y][x] == '.' || map[y][x] == 'O') &&
			possible_put_piece(map, piece, x, y))
			{
				ft_printf("%d %d\n", y, x);
				return (1);
			}
	}
	return (0);
}

int		skip_map(void)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, GOT_X))
		{
			ft_strdel(&line);
			get_next_line(0, &line);
			ft_strdel(&line);
			get_next_line(0, &line);
			ft_strdel(&line);
			break;
		}
		count++;
		ft_strdel(&line);
	}
	if (count < g_mapy)
		return (0);
	return (1);
}

int		continue_fill(char **map, t_coord *piece)
{
	if (!skip_map())
		return (0);
	del_map(&map);
	if (!get_map(&map))
		return (0);
	if (!(piece = get_piece()))
		return (0);
	if (!put_piece(map, piece))
	{
		free(piece);
		piece = NULL;
		return (0);
	}
	free(piece);
	piece = NULL;
	return (1);
}

void	first_algo(char **map)
{
	t_coord	*piece;

	piece = get_piece();
	put_piece(map, piece);
	free(piece);
	piece = NULL;
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