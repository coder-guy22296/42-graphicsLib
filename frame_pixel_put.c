/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:05:44 by cyildiri          #+#    #+#             */
/*   Updated: 2016/12/15 21:05:46 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

int	frame_pixel_put(t_scene *scene, t_vec2fc place_me)
{
	t_frame *frame;
	unsigned int *image;
	int pos;
//static int cnt = 0;


	frame = &(scene->cur_frame);
	image = (unsigned int *)frame->image;



//	ft_putstr("call: ");
//	ft_putnbr(cnt);
//	ft_putstr("\n");
	if (	place_me.x < 0 || place_me.x >= scene->cur_frame.width
		||	place_me.y < 0 || place_me.y >= scene->cur_frame.height
		||	place_me.color == 0x4F000000)
	{
		//ft_putstr("abort pixel put\n");
		return (1);
	}
//	if (place_me.y == 0)
//		pos = (int)place_me.x;
//	else
//		pos = frame->width * ((int)place_me.y - 1) + (int)place_me.x;
//	ft_putstr("place (");
//	ft_putnbr(place_me.x);
//	ft_putstr(",");
//	ft_putnbr(place_me.y);
//	ft_putstr(") frame size[");
//	ft_putnbr(scene->cur_frame.width);
//	ft_putstr(",");
//	ft_putnbr(scene->cur_frame.height);
//	ft_putstr("]\n");
	pos = place_me.x + place_me.y * frame->line_size/4;
//	ft_putstr("test2 test2 test2: ");
//	ft_putnbr(pos);
//	ft_putstr("\n");
	image[pos] = (unsigned int)(place_me.color);
	//ft_putstr("test2 test2 test2\n");
	//ft_putstr("pixel put\n");


//	cnt++;
//	ft_putstr("call: ");
//	ft_putnbr(cnt);
//	ft_putstr("\n");
	return (0);
}