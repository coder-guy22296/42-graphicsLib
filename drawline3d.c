/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:47:01 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/25 14:47:04 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	drawline3d(t_renderer renderer, t_vec3fc point_a, t_vec3fc point_b)
{
	t_vec3fc point1;
	t_vec3fc point2;

	point1 = renderer.scene->projection_method(*renderer.scene, point_a);
	point2 = renderer.scene->projection_method(*renderer.scene, point_b);
	point1.color = point_a.color;
	point2.color = point_b.color;
	drawline(renderer, point1, point2);
}
