/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:48:22 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/25 14:48:25 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	render_scene(t_renderer renderer, t_scene scene)
{
	int i;

	i = 0;
	while (i < scene.object_cnt)
	{
		render3d_object(renderer, scene.objects[i]);
		i++;
	}
}
