/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:02 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/23 17:48:03 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraphics.h"

t_vec2i	perspective_projection(t_scene scene, t_camera cam, t_vec3f point)
{
	t_vec3f new_point;
	t_vec2f projection;
	t_vec2f normalized_points;
	t_vec2f rasterized_points;

	//align points to world origin
	point.x += scene.origin.x;
	point.y += scene.origin.y;
	point.z += scene.origin.z;
	printf("World Coords        (%d,%d,%d)\n", point.x, point.y, point.z);

	//camera transform
	new_point.x = cos(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.x))
	- sin(cam.loc.rotation.y) * (point.z-cam.loc.z);

	new_point.y = sin(cam.loc.rotation.x) * (cos(cam.loc.rotation.y)
	* (point.z-cam.loc.z) + sin(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.x)))
	+ cos(cam.loc.rotation.x) * (cos(cam.loc.rotation.z) * (point.y-cam.loc.y)
	- sin(cam.loc.rotation.z) * (point.x-cam.loc.x));

	new_point.z = cos(cam.loc.rotation.x) * (cos(cam.loc.rotation.y)
	* (point.z-cam.loc.z) + sin(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.x)))
	- sin(cam.loc.rotation.x) * (cos(cam.loc.rotation.z) * (point.y-cam.loc.y)
	- sin(cam.loc.rotation.z) * (point.x-cam.loc.x));
	printf("Camera Coords       (%f,%f,%f)\n", new_point.x, new_point.y, new_point.z);

	// projection
	projection.x = (double)((((double)cam.viewer.z / fabs((double)new_point.z))
	* (double)new_point.x) - (double)cam.viewer.x);
	projection.y = (double)((((double)cam.viewer.z / fabs((double)new_point.z))
	* (double)new_point.y) - (double)cam.viewer.y);
	printf("Canvas Coords       (%f,%f)\n", projection.x, projection.y);

	// normalization + screen spacing
	normalized_points.x = (projection.x + 1)/2;
	normalized_points.y = (1 - projection.y)/2;
	printf("NDC         (%f,%f)\n", normalized_points.x, normalized_points.y);

	// rasterization
	rasterized_points.x = (int)(normalized_points.x * 1000);
	rasterized_points.y = (int)(normalized_points.y * 1000);
	printf("Rasterized Coords   (%d,%d)\n", rasterized_points.x, rasterized_points.y);
	return (rasterized_points);
}
