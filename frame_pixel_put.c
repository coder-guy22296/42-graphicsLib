/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:05:44 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/23 16:47:09 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"
#include <stdlib.h>
#include <stdio.h> //REMOVE

int	frame_pixel_put(t_scene *scene, t_vec2fc place_me)
{
	t_frame			*frame;
	unsigned int	*image;
	int				pos;

	frame = &(scene->cur_frame);
	image = (unsigned int *)frame->image;
	//printf("frame width: %d\n", frame->width);
	//printf("frame height: %d\n", frame->height);
	//printf("frame line_size: %d\n", frame->line_size);
	//printf("place x: %f\n", place_me.x);
	//printf("place y: %f\n", place_me.y);
	if (place_me.x < 0 || place_me.x >= scene->cur_frame.width
		|| place_me.y < 0 || place_me.y >= scene->cur_frame.height
		|| place_me.color == 0x4F000000)
	{

		//ft_putstr("bad frame draw pixel!!!\n");
		return (1);
	}
	pos = place_me.x + (place_me.y * frame->line_size / 4);
	image[pos] = (unsigned int)place_me.color;
	return (0);
}
