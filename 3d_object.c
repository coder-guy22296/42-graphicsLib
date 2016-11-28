/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:46:13 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 21:50:54 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

t_3d_object	*new_object3d(char *filename)
{
	t_3d_object *obj;

	if (!(obj = (t_3d_object *)ft_memalloc(sizeof(t_3d_object))))
		return (NULL);
	//load
	filename = "";//temp

	return (obj);
}
/*
t_3d_object	object3d(char *filename)
{
	t_3d_object obj;

	//load
	filename = "";//temp

	return (obj);
}
*/