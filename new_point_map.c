/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:49:10 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/20 17:08:37 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

/*
**	3d object constructor for a wireframe of specified vertices per face
*/

t_3d_object *new_point_map(int max_vertices)
{
    t_3d_object *obj;

    if (!(obj = (t_3d_object *)ft_memalloc(sizeof(t_3d_object))))
        return (NULL);
    obj->vertex_cnt = 0;
    obj->vertex_cnt_max = max_vertices;
    obj->faces_arr = 0;
    obj->face_cnt = 0;
	obj->pos_vector = vec6f(vec3f(0.0, 0.0, 0.0),vec3f(0.0, 0.0, 0.0));
    obj->vertices = (t_vec3fc *)ft_memalloc(sizeof(t_vec3fc) * max_vertices);
	return (obj);
}
