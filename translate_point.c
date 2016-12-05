/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:57 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/23 17:48:58 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

t_vec3f	translate_point(t_vec3f original, t_vec3f translation)
{
	t_vec3f translated_point;

	translated_point.x = original.x + translation.x;
	translated_point.y = original.y + translation.y;
	translated_point.z = original.z + translation.z;
	return (translated_point);
}
