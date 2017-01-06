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

static int	extract_byte(int target, int bits_from_right)
{
	return ((target & (255 << bits_from_right)) >> bits_from_right);
}

t_color		color(int color32)
{
	t_color str_color;
	
	str_color.red = extract_byte(color32, RED);
	str_color.green = extract_byte(color32, GREEN);
	str_color.blue = extract_byte(color32, BLUE);
	str_color.alpha = extract_byte(color32, ALPHA);
	return (str_color);
}

int			blend(int color_a, int color_b, float percentage)
{
	t_color	str_color1;
	t_color	str_color2;
	t_color	delta;
	int 	blend;
	
	blend = 0;
	str_color1 = color(color_a);
	str_color2 = color(color_b);
	if (color_a == color_b || percentage < 0.000001)
		return (color_a);
	delta.red = abs((str_color2.red - str_color1.red));
	delta.green = abs((str_color2.green - str_color1.green));
	delta.blue = abs((str_color2.blue - str_color1.blue));
	if (color_a < color_b)
		blend = (((int)(str_color1.red + (delta.red * percentage)))<<16)
				| (((int)(str_color1.green + (delta.green * percentage)))<<8)
				| ((int)(str_color1.blue + (delta.blue * percentage)));
	else if (color_a > color_b)
		blend = (((int)(str_color1.red - (delta.red * percentage)))<<16)
				| (((int)(str_color1.green - (delta.green * percentage)))<<8)
				| ((int)(str_color1.blue - (delta.blue * percentage)));
	return (blend);
}

void		drawline(t_renderer *renderer, t_vec3fc point_a, t_vec3fc point_b)
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



	//ft_putstr("line drawn!");

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
		frame_pixel_put(renderer->scene, vec2fc(x, y, blend(start.color, end.color, (fabsf((float)y - start.y))/abs(deltay))));
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
		frame_pixel_put(renderer->scene, vec2fc(x, y, blend(start.color, end.color, (fabsf((float)x - start.x))/abs(deltax))));
		error += deltaerr;
		if (error >= 0.0)
		{
			y += ydir;
			error -= 1.0;
		}
		x += xdir;
	}
}
