/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:48:22 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/25 14:48:25 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"
#include <stdio.h>
#include <stdlib.h>

void	render_scene(t_renderer *renderer, t_scene scene)
{
	t_list *current;

	current = scene.objects;
	//malloc new frame
	renderer->scene->cur_frame.id = mlx_new_image(renderer->mlx,
										  renderer->win_x,
										  renderer->win_y);
	//ft_putstr("test test test\n");
	if (!renderer->scene->cur_frame.color_depth)
		renderer->scene->cur_frame.image = mlx_get_data_addr(renderer->scene->cur_frame.id, &(renderer->scene->cur_frame.color_depth), &(renderer->scene->cur_frame.line_size), &(renderer->scene->cur_frame.endien));
//	ft_putstr("bits per color: ");
//	ft_putnbr(renderer->scene->cur_frame.color_depth);
//	ft_putstr("\tbytes per line: ");
//	ft_putnbr(renderer->scene->cur_frame.line_size);
//	ft_putstr("\tendian: ");
//	ft_putnbr(renderer->scene->cur_frame.endien);
//	ft_putstr("\n");

	if (current)
	{
		while (current->next)
		{
			render3d_object(renderer, *((t_3d_object *)(current->content)));
			current = current->next;
		}
		render3d_object(renderer, *((t_3d_object *)(current->content)));
	}
	/*int i = 0;
	while (i < 1000000)
	{
		ft_putnbr(((int *)renderer->scene->cur_frame.image)[i]);
		i++;
	}*/

//	int i, j;
//	for (i = 0; i < 50; i++)
//	{
//		for (j = 0; j < 50; j++)
//		{
//			renderer->scene->cur_frame.image[4 * i + 4000 * j] = 255;
//			renderer->scene->cur_frame.image[4 * i + 4000 * j + 1] = 255;
//			renderer->scene->cur_frame.image[4 * i + 4000 * j + 2] = 0;
//		}
//	}
	//renderer->scene->cur_frame.image[1] = 255;
	//renderer->scene->cur_frame.image[2] = 255;
	//render frame to window
	mlx_put_image_to_window(renderer->mlx, renderer->window,
							renderer->scene->cur_frame.id, 0, 0);
	mlx_pixel_put(renderer->mlx, renderer->window, 50, 50, 0xff0000);

	//free the frame
	mlx_destroy_image(renderer->mlx, renderer->scene->cur_frame.id);
}
