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

t_vec6f	rotate(vec6f *obj_vector, vec3f rotation)
{
    // rotate along x axis
    obj_vector.position.y = obj_vector.position.y * cos(rotation.x);
    obj_vector.position.z = obj_vector.position.y * sin(rotation.x);
    // rotate along y axis
    obj_vector.position.x = obj_vector.position.x * cos(rotation.y);
    obj_vector.position.z = obj_vector.position.x * sin(rotation.y);
    // rotate along z axis
    obj_vector.position.x = obj_vector.position.x * cos(rotation.z);
    obj_vector.position.y = obj_vector.position.x * sin(rotation.z);
    // set rotation properties
    obj_vector.rotation.x = rotation.x;
    obj_vector.rotation.y = rotation.y;
    obj_vector.rotation.z = rotation.z;
    return (*obj_vector);
}