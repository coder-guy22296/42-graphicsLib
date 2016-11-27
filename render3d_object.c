/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:48:04 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/25 14:48:05 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	render3d_object(t_renderer renderer, t_3d_object obj)
{
	int cur_face;
	int cur_vertex;
	int *face_vertices;
	int next_vertex;
	t_vec3f vert1;
	t_vec3f vert2;

	mode = -99;
	cur_face = 0;
	cur_vertex = 0;
	face_vertices = obj.vertex_ind;
	while (cur_face < obj.face_cnt)
	{
		cur_vertex = 0;
		while (cur_vertex < obj.faces_arr[cur_face])
		{
			if (cur_vertex + 1 < obj.faces_arr[cur_face])
				next_vertex = cur_vertex + 1;
			else
				next_vertex = 0;
			vert1 = translate(obj.vertices[face_vertices[cur_vertex]], obj.pos_vector);
			vert2 = translate(obj.vertices[face_vertices[next_vertex]], obj.pos_vector);
			drawline3d(renderer, &vert1, &vert2);
			cur_vertex++;
		}
		face_vertices = &face_vertices[cur_vertex];
		cur_face++;
	}
}