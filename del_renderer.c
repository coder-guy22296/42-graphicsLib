/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:04:24 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/27 13:04:27 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

void	del_renderer(t_renderer *renderer)
{
	//mlx_destroy_window(renderer->mlx, renderer->window);
	del_scene(renderer->scene);
	//free(mlx);
}