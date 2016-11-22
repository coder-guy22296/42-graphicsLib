/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:30:51 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 22:37:25 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

t_scene	*new_scene(void (*projection_method)(t_scene))
{
	t_scene *scene3d;

	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		return (NULL);
	scene->projection_method = projection_method;
	return (scene3d);
}

t_scene scene(void (*projection_method)(t_scene))
{
	t_scene scene3d;
	
	scene3d.projection_method = projection_method;
	return (scene3d)
}
