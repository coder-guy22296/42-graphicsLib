/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map_add_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:52:50 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/19 21:09:13 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	point_map_add_point(t_3d_object *point_map, t_vec3fc point)
{
	if (point_map->vertex_cnt >= point_map->vertex_cnt_max)
	{
		point_map->verticies[point_map->vertex_cnt] = point;
		point_map->vertex_cnt++;
	}
}
