/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:49:15 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/23 17:49:16 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	rotate_object(t_3d_object *obj, t_vec3f rotation)
{
	int		index;

	index = 0;
	while (index < obj->vertex_cnt)
	{
		float sin_t;
		float cos_t;
		t_vec3f original;
		t_vec3f *new_point;

		original = obj->vertices[index];
		new_point = &obj->vertices[index];
		printf("rotating from: (%f,%f,%f)\n", obj->vertices[index].x,obj->vertices[index].y,obj->vertices[index].z);
		if (rotation.x)
		{
			sin_t = sin(rotation.x);
			cos_t = cos(rotation.x);
			// rotate along x axis
			new_point->y = original.y * cos_t - original.z * sin_t;
			new_point->z = original.z * cos_t + original.y * sin_t;
		}
		original = obj->vertices[index];
		new_point = &obj->vertices[index];
		if (rotation.y)
		{
			sin_t = sin(rotation.y);
			cos_t = cos(rotation.y);
			// rotate along y axis
			new_point->x = original.x * cos_t - original.z * sin_t;
			new_point->z = original.z * cos_t + original.x * sin_t;
		}
		original = obj->vertices[index];
		new_point = &obj->vertices[index];
		if (rotation.z)
		{
			sin_t = sin(rotation.z);
			cos_t = cos(rotation.z);
			// rotate along z axis
			new_point->x = original.x * cos_t - original.y * sin_t;
			new_point->y = original.y * cos_t + original.x * sin_t;
		}
		printf("rotated to: (%f,%f,%f)\n", obj->vertices[index].x,obj->vertices[index].y,obj->vertices[index].z);
		index++;
	}
	obj->pos_vector.rotation.x += rotation.x;
	obj->pos_vector.rotation.y += rotation.y;
	obj->pos_vector.rotation.z += rotation.z;
}
