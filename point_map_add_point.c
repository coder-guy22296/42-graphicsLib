/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map_add_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:52:50 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/20 17:36:47 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	point_map_add_point(t_3d_object *point_map, t_vec3fc point)
{
	if (point_map->vertex_cnt < point_map->vertex_cnt_max)
	{
		point_map->vertices[point_map->vertex_cnt] = point;
		(point_map->vertex_cnt)++;
	}
}
