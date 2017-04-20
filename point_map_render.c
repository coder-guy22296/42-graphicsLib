/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:50:03 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/19 21:03:24 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void    point_map_render(t_renderer *renderer, t_3d_object obj)
{
    int			cur_vertex;
    t_vec3fc    vert1;
	t_vec3fc	point;
	t_vec2fc	projection;

    cur_vertex = 0;
    while (cur_vertex < obj.vertex_cnt)
    {
        vert1 = translate_point(obj.vertices[cur_vertex],
                                obj.pos_vector.position);
		point = orthographic_projection(renderer->scene, vert1);
		projection.x = point.x;
		projection.y = point.y;
    	projection.color = point.color;
		frame_pixel_put(renderer->scene, projection);
        cur_vertex++;
     }
}
