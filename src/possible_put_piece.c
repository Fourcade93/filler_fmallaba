/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_put_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:41:13 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/16 13:31:28 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int possible_put_piece(char **map, char **piece, int start_x, int y)
{
	int i;
	int j;
	int x;
	int check;

	i = -1;
	check = 0;
	while (piece[++i])
	{
		j = -1;
		x = start_x;
		while (piece[i][++j])
		{
			if (x >= g_mapx || (piece[i][j] == '*' && map[y][x] == g_enemy) ||
				check > 1)
				return (0);
			if (map[y][x] == g_i_am && piece[i][j] == '*')
				check++;
			x++;
		}
		y++;
	}
	if (check != 1)
		return (0);
	return (1);
}
