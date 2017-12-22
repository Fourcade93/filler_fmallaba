/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:17:06 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/22 13:53:21 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos	*top_left(void)
{
	t_pos	*arr;

	arr = (t_pos*)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = 0;
	(arr[0]).diry = g_mapy - 1;
	(arr[1]).dirx = 0;
	(arr[1]).diry = g_mapy / 2;
	(arr[2]).dirx = g_mapx - 1;
	(arr[2]).diry = g_mapy / 2;
	(arr[3]).dirx = g_mapx - 1;
	(arr[3]).diry = g_mapy - 1;
	(arr[4]).dirx = g_mapx / 2;
	(arr[4]).diry = 0;
	(arr[5]).dirx = 0;
	(arr[5]).diry = 0;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos *top_right(void)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = g_mapx - 1;
	(arr[0]).diry = g_mapy - 1;
	(arr[1]).dirx = g_mapx - 1;
	(arr[1]).diry = g_mapy / 2;
	(arr[2]).dirx = 0;
	(arr[2]).diry = g_mapy / 2;
	(arr[3]).dirx = 0;
	(arr[3]).diry = g_mapy - 1;
	(arr[4]).dirx = g_mapx / 2;
	(arr[4]).diry = 0;
	(arr[5]).dirx = g_mapx - 1;
	(arr[5]).diry = 0;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos *bottom_left(void)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = 0;
	(arr[0]).diry = 0;
	(arr[1]).dirx = 0;
	(arr[1]).diry = g_mapy / 2;
	(arr[2]).dirx = g_mapx - 1;
	(arr[2]).diry = g_mapy / 2;
	(arr[3]).dirx = g_mapx - 1;
	(arr[3]).diry = 0;
	(arr[4]).dirx = g_mapx / 2;
	(arr[4]).diry = g_mapy - 1;
	(arr[5]).dirx = 0;
	(arr[5]).diry = g_mapy - 1;
	(arr[6]).dirx = -1;
	return (arr);
}

t_pos *bottom_right(void)
{
	t_pos *arr;

	arr = (t_pos *)malloc(sizeof(t_pos) * 7);
	(arr[0]).dirx = g_mapx - 1;
	(arr[0]).diry = 0;
	(arr[1]).dirx = g_mapx - 1;
	(arr[1]).diry = g_mapy / 2;
	(arr[2]).dirx = 0;
	(arr[2]).diry = g_mapy / 2;
	(arr[3]).dirx = 0;
	(arr[3]).diry = 0;
	(arr[4]).dirx = g_mapx / 2;
	(arr[4]).diry = g_mapy - 1;
	(arr[5]).dirx = g_mapx - 1;
	(arr[5]).diry = g_mapy - 1;
	(arr[6]).dirx = -1;
	return (arr);
}
