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
#include <stdio.h> // REMOVE
#define RED 16
#define GREEN 8
#define BLUE 0
int	blend(int color_a, int color_b, int steps, int start,  int cur) {
	static int delta;

	float red_a = (color_a & (255 << 16)) >> 16;
	float green_a = (color_a & (255 << 8)) >> 8;
	float blue_a = (color_a & (255 << 0));

	float red_b = (color_b & (255 << 16)) >> 16;
	float green_b = (color_b & (255 << 8)) >> 8;
	float blue_b = (color_b & (255 << 0));

	float dr;
	float dg;
	float db;



	int blend;

	cur = abs(cur - start);


	dr = fabsf((red_b - red_a) / steps);
	dg = fabsf((green_b - green_a) / steps);
	db = fabsf((blue_b - blue_a) / steps);

	//blend = color_a | ((red_a + (dr*cur))<<16) | ((green_a + (dg*cur))<<8) | (blue_a + (db*cur));
	 if (color_a < color_b)
	 {
		blend = (((int)(red_a + (dr*cur)))<<16) | (((int)(green_a + (dg*cur)))<<8) | ((int)(blue_a + (db*cur)));

	 }
	 else if (color_a > color_b)
	 {
	 	//dr = (red_a - red_b) / steps;
	 	//dg = (green_a - green_b) / steps;
	 	//db = (blue_a - blue_b) / steps;
	 	//blend = color_b | ((red_b - (dr*cur))<<16) | ((green_b - (dg*cur))<<8) | (blue_b - (db*cur));
		blend = (((int)(red_a - (dr*cur)))<<16) | (((int)(green_a - (dg*cur)))<<8) | ((int)(blue_a - (db*cur)));

	 }
	 else
	 	return (color_a);

	if (blend == 0x00000000)
		ft_putstr("RENDERED BLACK PIXEL!!!!\n");

//	ft_putstr("cur: ");
//	ft_putnbr(cur);
//
//	ft_putstr("\t\tsteps: ");
//	ft_putnbr(steps);
//
//	ft_putstr("\t\tdelta red: ");
//	ft_putnbr(dr);
//
//	ft_putstr("\t\tdelta green: ");
//	ft_putnbr(dg);
//
//	ft_putstr("\t\tdelta blue: ");
//	ft_putnbr(db);
//
//	ft_putstr("\t\tred: ");
//	ft_putnbr((blend & (255 << 16)) >> 16);
//
//	ft_putstr("\t\tgreen: ");
//	ft_putnbr((blend & (255 << 8)) >> 8);
//
//	ft_putstr("\t\tblue: ");
//	ft_putnbr((blend & (255 << 0)) >> 0);
//
//	ft_putstr("\n");
//	ft_putstr("color: ");
//	ft_putnbr(blend);
//	ft_putstr("\n");

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
	t_vec3fc start;
	t_vec3fc end;



	if (point_a.x > point_b.x)
	{
		start = point_a;
		end = point_b;
	}
	else
	{
		start = point_b;
		end = point_a;
	}

	deltax = (int)end.x - (int)start.x;
	deltay = (int)end.y - (int)start.y;
	if (deltax == 0)
		slope = 0;
	else
		slope = (double)deltay / (double)deltax;
	error = -1.0;
	deltaerr = fabs(slope);
	xdir = 1;
	ydir = 1;
	x = (int)start.x;
	y = (int)start.y;
	if (deltax < 0)
		xdir = -1;
	if (deltay < 0)
		ydir = -1;
	while ((fabs(slope) > 1.0 || deltax == 0) && y != (int)end.y/* + ydir*/)
	{
		deltaerr = fabs((double)deltax / (double)deltay);
		if (y == start.y)
		{

			error += deltaerr;
		}

		mlx_pixel_put(renderer.mlx, renderer.window, x, y, blend(start.color, end.color, abs(deltay), (int)start.y, y))/*(point_a.z < point_b.z) ? point_a.color : point_b.color)*/;
		error += deltaerr;
		//printf("error: %f\n", error);
		if (error >= 0.0)
		{
			x += xdir;
			error -= 1.0;
		}
		y += ydir;
	}

	/*
	**
	*/

	error += deltaerr;
	while (fabs(slope) <= 1.0 && x != (int)end.x/* + xdir*/)
	{
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, blend(start.color, end.color, abs(deltax), (int)start.x, x))/*(point_a.z < point_b.z) ? point_a.color : point_b.color)*/;
		error += deltaerr;
		if (error >= 0.0)
		{
			y += ydir;
			error -= 1.0;
		}
		x += xdir;
	}
}
