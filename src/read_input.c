/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:18:33 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 21:44:53 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	continue_fill(char **map, t_pos *pos, t_pos map_size)
{
	int		i;
	int		piece_y;
	char	**piece;

	i = -1;
	piece_y = get_piece(&piece);
	while (pos[++i].dirx != -1)
		while (check_point(map, pos[i]))
		{
			if (!put_piece(map, piece, piece_y, pos[i]))
				return ;
			del_map(&map);
			del_map(&piece);
			get_map(&map, map_size);
			piece_y = get_piece(&piece);
		}
	(pos[i]).dirx = map_size.my_x / 2;
	(pos[i]).diry = map_size.my_y / 2;
	while (put_piece(map, piece, piece_y, pos[i]))
	{
		del_map(&map);
		del_map(&piece);
		get_map(&map, map_size);
		piece_y = get_piece(&piece);
	}
}

void	first_algo(char **map, t_pos map_size)
{
	t_pos	*pos;

	pos = get_pos(map, map_size);
	continue_fill(map, pos, map_size);
	ft_printf("%d %d\n", 0, 0);
}

void	read_map(t_pos map_size)
{
	char	**map;
	char	*line;

	map = (char**)ft_memalloc(sizeof(char*) * (map_size.my_y + 1));
	get_next_line(0, &line);
	ft_strdel(&line);
	get_map(&map, map_size);
	if (g_i_am == 'O')
		g_enemy = 'X';
	else
		g_enemy = 'O';
	first_algo(map, map_size);
	free(map);
}

int		main(void)
{
	char	*line;
	t_pos	map_size;

	line = NULL;
	map_size.my_x = 0;
	map_size.my_y = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "p1") && ft_strstr(line, NAME))
			g_i_am = 'O';
		if (ft_strstr(line, "p2") && ft_strstr(line, NAME))
			g_i_am = 'X';
		if (ft_strstr(line, "Plateau"))
		{
			map_size.my_x = ft_atoi(ft_strchr(line, ' '));
			map_size.my_y = ft_atoi(ft_strrchr(line, ' '));
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	read_map(map_size);
	return (0);
}