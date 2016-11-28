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

t_vec6f	rotate(t_vec6f *obj_vector, t_vec3f rotation)
{
	obj_vector->rotation.x = rotation.x;
	obj_vector->rotation.y = rotation.y;
	obj_vector->rotation.z = rotation.z;
	return (*obj_vector);
}
