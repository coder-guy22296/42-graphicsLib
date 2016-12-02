/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:57 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/23 17:48:58 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	translate(t_3d_object *obj, t_vec3f translation)
{
	int		index;

	index = 0;
	while (index < obj->vertex_cnt)
	{
		obj->vertices[index].x += translation.x;
		obj->vertices[index].y += translation.y;
		obj->vertices[index].z += translation.z;
		index++;
	}
	obj->pos_vector.position.x += translation.x;
	obj->pos_vector.position.y += translation.y;
	obj->pos_vector.position.z += translation.z;
}
