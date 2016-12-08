/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:46:39 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/25 14:46:41 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libgraphics.h"
#define RED 16
#define GREEN 8
#define BLUE 0
int	blend(int color_a, int color_b, int steps, int cur) {
	static int delta;

	int red_a = color_a & (255 << 16) >> 16;
	int green_a = color_a & (255 << 8) >> 8;
	int blue_a = color_a & (255 << 0);

	int red_b = color_b & (255 << 16) >> 16;
	int green_b = color_b & (255 << 8) >> 8;
	int blue_b = color_b & (255 << 0);

	int dr;
	int dg;
	int db;



	int blend;
	if (color_a < color_b)
	{
		dr = (red_b - red_a) / steps;
		dg = (green_b - green_a) / steps;
		db = (blue_b - blue_a) / steps;
		blend = color_a | ((red_a + (dr*cur))<<16) | ((green_a + (dg*cur))<<8) | (blue_a + (db*cur));

	}
	else if (color_a > color_b)
	{
		dr = (red_a - red_b) / steps;
		dg = (green_a - green_b) / steps;
		db = (blue_a - blue_b) / steps;
		blend = color_b | ((red_b + (dr*cur))<<16) | ((green_b + (dg*cur))<<8) | (blue_b + (db*cur));

	}
	else
		return (color_a);

	if (blend == 0x00000000)
		ft_putstr("RENDERED BLACK PIXEL!!!!\n");

	return (blend);
	if (color_a > color_b) {
		delta = (color_a - color_b) / steps;
		return (color_b + (delta * cur));
	} else {
		delta = (color_b - color_a) / steps;
		return (color_a + (delta * cur));
	}
}
/*
int	blend2(t_vec3fc point_a, t_vec3fc point_b, int x, int y) {
	static int delta;

	int red_a = color_a & (255 << 16) >> 16;
	int green_a = color_a & (255 << 8) >> 8;
	int blue_a = color_a & (255 << 0);

	int red_b = color_b & (255 << 16) >> 16;
	int green_b = color_b & (255 << 8) >> 8;
	int blue_b = color_b & (255 << 0);

	int dr = (red_b - red_a) / steps;
	int dg = (green_b - green_a) / steps;
	int db = (blue_b - blue_a) / steps;
	int blend = color_a | ((red_a + (dr*cur))<<16) | ((green_a + (dg*cur))<<8) | (blue_a + (db*cur));

	return (blend);
}
*/
void	drawline(t_renderer renderer, t_vec3fc point_a, t_vec3fc point_b)
{
	int		deltax;
	int		deltay;
	double	slope;
	double	error;
	double	deltaerr;
	int		xdir;
	int		ydir;
	int		x;
	int		y;

	deltax = point_b.x - point_a.x;
	deltay = point_b.y - point_a.y;
	if (deltax == 0)
		slope = 0;
	else
		slope = (double)deltay / (double)deltax;
	error = -1.0;
	deltaerr = fabs(slope);
	xdir = 1;
	ydir = 1;
	x = point_a.x;
	y = point_a.y;
	if (deltax < 0)
		xdir = -1;
	if (deltay < 0)
		ydir = -1;
	while ((fabs(slope) > 1.0 || deltax == 0) && y != point_b.y)
	{
		if (y == point_a.y)
		{
			deltaerr = fabs((double)deltax / (double)deltay);
			error += deltaerr;
		}
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, blend(point_a.color, point_b.color, (abs(deltax) > abs (deltay)) ? abs(deltax):abs(deltay), (abs(deltax) > abs (deltay)) ? x - point_a.x: y - point_a.y))/*(point_a.z < point_b.z) ? point_a.color : point_b.color)*/;
		error += deltaerr;
		if (error >= 0.0)
		{
			x += xdir;
			error -= 1.0;
		}
		y += ydir;
	}
	error += deltaerr;
	while (fabs(slope) <= 1.0 && x != point_b.x)
	{
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, blend(point_a.color, point_b.color, (abs(deltax) > abs (deltay)) ? abs(deltax):abs(deltay), (abs(deltax) > abs (deltay)) ? x - point_a.x: y - point_a.y))/*(point_a.z < point_b.z) ? point_a.color : point_b.color)*/;
		error += deltaerr;
		if (error >= 0.0)
		{
			y += ydir;
			error -= 1.0;
		}
		x += xdir;
	}
}
