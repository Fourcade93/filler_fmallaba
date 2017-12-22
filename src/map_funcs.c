/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:38:15 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 21:25:23 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece(char ***piece)
{
	int piece_x;
	int piece_y;
	int i;
	char *line;

	if (!get_next_line(0, &line))
		return (0);
	piece_y = ft_atoi(ft_strchr(line, ' '));
	piece_x = ft_atoi(ft_strrchr(line, ' '));
	*piece = (char **)ft_memalloc(sizeof(char *) * (piece_y + 1));
	i = -1;
	ft_strdel(&line);
	while (++i < piece_y && get_next_line(0, &line))
		(*piece)[i] = line;
	(*piece)[i] = 0;
	return (piece_y);
}

int		get_map(char ***map, t_pos map_size)
{
	int i;
	char *line;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '0')
			(*map)[i++] = ft_strsub(line, 4, map_size.my_x);
		if (ft_atoi(line) == map_size.my_y - 1)
			break;
		ft_strdel(&line);
	}
	(*map)[i] = 0;
	ft_strdel(&line);
	if (i < map_size.my_y)
		return (0);
	return (1);
}

void	del_map(char ***map)
{
	int i;

	i = -1;
	while ((*map)[++i])
		ft_strdel(&((*map)[i]));
}
