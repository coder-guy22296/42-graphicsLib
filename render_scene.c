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
#include <stdio.h>
#include <stdlib.h>

void	render_scene(t_renderer renderer, t_scene scene)
{
	t_list *current;

	current = scene.objects;
	if (current)
	{
		while (current->next)
		{
			render3d_object(renderer, *((t_3d_object *)(current->content)));
			current = current->next;
		}
		render3d_object(renderer, *((t_3d_object *)(current->content)));
	}
}
