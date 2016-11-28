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

t_vec3f	translate(t_vec3f *obj_vector, t_vec3f translation)
{
	obj_vector->x += translation.x;
	obj_vector->y += translation.y;
	obj_vector->z += translation.z;
	return (*obj_vector);
}
