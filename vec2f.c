/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:10:20 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 21:14:00 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

t_vec2f	*new_vec2f(float x, float y)
{
    t_vec2f	*point;

	if (!(point = (t_vec2f *)ft_memalloc(sizeof(t_vec2f))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

t_vec2f	vec2f(float x, float y)
{
	t_vec2f	point;

	point.x = x;
	point.y = y;
	return (point);
}
