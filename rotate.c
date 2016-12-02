/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:49:15 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/23 17:49:16 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	rotate(t_3d_object *obj, t_vec3f rotation)
{
	int		index;

	index = 0;
	while (index < obj->vertex_cnt)
	{
		// rotate along x axis
		obj->vertices[index].y = obj->vertices[index].y * cos(rotation.x);
		obj->vertices[index].z = obj->vertices[index].y * sin(rotation.x);
		// rotate along y axis
		obj->vertices[index].x = obj->vertices[index].x * cos(rotation.y);
		obj->vertices[index].z = obj->vertices[index].x * sin(rotation.y);
		// rotate along z axis
		obj->vertices[index].x = obj->vertices[index].x * cos(rotation.z);
		obj->vertices[index].y = obj->vertices[index].x * sin(rotation.z);
		index++;
	}
	obj->pos_vector.rotation.x += rotation.x;
	obj->pos_vector.rotation.y += rotation.y;
	obj->pos_vector.rotation.z += rotation.z;
}
