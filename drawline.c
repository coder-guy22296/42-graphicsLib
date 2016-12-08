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

int	blend(int color_a, int color_b, int steps, int cur) {
	static int delta;

	if (color_a > color_b) {
		delta = (color_a - color_b) / steps;
		return (color_b + (delta * cur));
	} else {
		delta = (color_b - color_a) / steps;
		return (color_a + (delta * cur));
	}
}

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
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, (point_a.z < point_b.z) ? point_a.color : point_b.color);
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
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, (point_a.z < point_b.z) ? point_a.color : point_b.color);
		error += deltaerr;
		if (error >= 0.0)
		{
			y += ydir;
			error -= 1.0;
		}
		x += xdir;
	}
}
