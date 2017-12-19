/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:35:17 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/19 18:10:08 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_max_y(char **piece)
{
	int y;
	int	x;
	int min_y;
	int max_y;

	y = -1;
	max_y = -1;
	min_y = -1;
	while (piece[++y])
	{
		x = -1;
		while (piece[y][++x])
		{
			if (piece[y][x] == '*' && min_y == -1)
				min_y = y;
			if (piece[y][x] == '*' && min_y != -1)
				max_y = y;
		}
	}
	if (max_y > min_y)
		return (max_y - min_y);
	return (1);
}

int	get_max_x(char **piece)
{
	int y;
	int x;
	int min_x;
	int max_x;

	x = -1;
	max_x = -1;
	min_x = -1;
	while (piece[0][++x])
	{
		y = -1;
		while (piece[++y])
		{
			if (piece[y][x] == '*' && min_x == -1)
				min_x = x;
			if (piece[y][x] == '*' && min_x != -1)
				max_x = x;
		}
	}
	if (max_x > min_x)
		return (max_x - min_x);
	return (1);
}

int	check_piece(char **piece)
{
	int	max_x;
	int	max_y;

	max_x = get_max_x(piece);
	max_y = get_max_y(piece);
	if (max_x >= max_y)
		return (0);
	return (1);
}