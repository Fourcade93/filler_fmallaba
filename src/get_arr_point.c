/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:17:06 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/23 12:00:52 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos	*top_left(t_pos map_size)
{
	t_pos	*arr;

	arr = (t_pos*)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = 0;
	(arr[0]).diry = map_size.my_y - 1;
	(arr[1]).dirx = 0;
	(arr[1]).diry = map_size.my_y / 2;
	(arr[2]).dirx = map_size.my_x - 1;
	(arr[2]).diry = map_size.my_y / 2;
	(arr[3]).dirx = map_size.my_x - 1;
	(arr[3]).diry = map_size.my_y - 1;
	(arr[4]).dirx = map_size.my_x / 2;
	(arr[4]).diry = 0;
	(arr[5]).dirx = 0;
	(arr[5]).diry = 0;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos	*top_right(t_pos map_size)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = map_size.my_x - 1;
	(arr[0]).diry = map_size.my_y - 1;
	(arr[1]).dirx = map_size.my_x - 1;
	(arr[1]).diry = map_size.my_y / 2;
	(arr[2]).dirx = 0;
	(arr[2]).diry = map_size.my_y / 2;
	(arr[3]).dirx = 0;
	(arr[3]).diry = map_size.my_y - 1;
	(arr[4]).dirx = map_size.my_x / 2;
	(arr[4]).diry = 0;
	(arr[5]).dirx = map_size.my_x - 1;
	(arr[5]).diry = 0;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos	*bottom_left(t_pos map_size)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = 0;
	(arr[0]).diry = 0;
	(arr[1]).dirx = 0;
	(arr[1]).diry = map_size.my_y / 2;
	(arr[2]).dirx = map_size.my_x - 1;
	(arr[2]).diry = map_size.my_y / 2;
	(arr[3]).dirx = map_size.my_x - 1;
	(arr[3]).diry = 0;
	(arr[4]).dirx = map_size.my_x / 2;
	(arr[4]).diry = map_size.my_y - 1;
	(arr[5]).dirx = 0;
	(arr[5]).diry = map_size.my_y - 1;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos	*bottom_right(t_pos map_size)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = map_size.my_x - 1;
	(arr[0]).diry = 0;
	(arr[1]).dirx = map_size.my_x - 1;
	(arr[1]).diry = map_size.my_y / 2;
	(arr[2]).dirx = 0;
	(arr[2]).diry = map_size.my_y / 2;
	(arr[3]).dirx = 0;
	(arr[3]).diry = 0;
	(arr[4]).dirx = map_size.my_x / 2;
	(arr[4]).diry = map_size.my_y - 1;
	(arr[5]).dirx = map_size.my_x - 1;
	(arr[5]).diry = map_size.my_y - 1;
	(arr[6]).dirx = -1;
	return (arr);
}
