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

#include "libgraphics.h"

void	drawline(t_renderer renderer, vec2f point_a, vec2f point_b)
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
		slope = (double)deltay/(double)deltax;
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
			deltaerr = fabs((double)deltax/(double)deltay);
			error += deltaerr;
		}
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, 0x00FF00FF);
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
		mlx_pixel_put(renderer.mlx, renderer.window, x, y, 0x00FF00FF);
		error += deltaerr;
		if (error >= 0.0)
		{
			y += ydir;
			error -= 1.0;
		}
		x += xdir;
	}
}
