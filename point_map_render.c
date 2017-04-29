/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:50:03 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/23 16:46:53 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"
#include <stdio.h>

void    point_map_render(t_renderer *renderer, t_3d_object obj)
{
    int			cur_vertex;
    t_vec3fc    vert1;
	t_vec3fc	point;
	t_vec2fc	projection;

	//ft_putstr("render point map start\n");
    cur_vertex = 0;
    while (cur_vertex < obj.vertex_cnt)
    {
		//ft_putstr("attempting to render a point on the frame\n");
        vert1 = translate_point(obj.vertices[cur_vertex], obj.pos_vector.position);
		//vert1 = obj.vertices[cur_vertex];
		//printf("coord: (%f, %f, %f) --> ", vert1.x, vert1.y, vert1.z);
		point = perspective_projection(*renderer->scene, vert1);
		projection.x = point.x;
		projection.y = point.y;
    	projection.color = point.color;
		//printf("projection: (%f,%f)\n", projection.x, projection.y);
		frame_pixel_put(renderer->scene, projection);
        cur_vertex++;
    }
    point = perspective_projection(*renderer->scene, obj.pos_vector.position);
	projection.x = point.x;
	projection.y = point.y;
	projection.color = 0x00FF0000;
	//printf("pos projection: (%f,%f)\n", projection.x, projection.y);
	frame_pixel_put(renderer->scene, projection);
}
