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

#include <math.h>
#include "libgraphics.h"

t_vec2f	perspective_projection(t_scene scene, t_vec3f point)
{
	t_vec3f new_point;
	t_vec2f projection;
	t_vec2f normalized_points;
	t_vec2f rasterized_points;
	t_camera cam;

	cam = *(scene.camera);
	//align points to world origin_point
	point.x += scene.origin_point.x;
	point.y += scene.origin_point.y;
	point.z += scene.origin_point.z;
	//printf("World Coords        (%d,%d,%d)\n", point.x, point.y, point.z);

	//camera transform
	new_point.x = cos(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.position.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.position.x))
	- sin(cam.loc.rotation.y) * (point.z-cam.loc.position.z);

	new_point.y = sin(cam.loc.rotation.x) * (cos(cam.loc.rotation.y)
	* (point.z-cam.loc.position.z) + sin(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.position.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.position.x)))
	+ cos(cam.loc.rotation.x) * (cos(cam.loc.rotation.z) * (point.y-cam.loc.position.y)
	- sin(cam.loc.rotation.z) * (point.x-cam.loc.position.x));

	new_point.z = cos(cam.loc.rotation.x) * (cos(cam.loc.rotation.y)
	* (point.z-cam.loc.position.z) + sin(cam.loc.rotation.y) * (sin(cam.loc.rotation.z)
	* (point.y-cam.loc.position.y) + cos(cam.loc.rotation.z) * (point.x-cam.loc.position.x)))
	- sin(cam.loc.rotation.x) * (cos(cam.loc.rotation.z) * (point.y-cam.loc.position.y)
	- sin(cam.loc.rotation.z) * (point.x-cam.loc.position.x));
	//printf("Camera Coords       (%f,%f,%f)\n", new_point.x, new_point.y, new_point.z);

	// projection
	projection.x = (double)((((double)cam.viewer.z / fabs((double)new_point.z))
	* (double)new_point.x) - (double)cam.viewer.x);
	projection.y = (double)((((double)cam.viewer.z / fabs((double)new_point.z))
	* (double)new_point.y) - (double)cam.viewer.y);
	//printf("Canvas Coords       (%f,%f)\n", projection.x, projection.y);

	// normalization + screen spacing
	normalized_points.x = (projection.x + 1)/2;
	normalized_points.y = (1 - projection.y)/2;
	//printf("NDC         (%f,%f)\n", normalized_points.x, normalized_points.y);

	// rasterization
	rasterized_points.x = (int)(normalized_points.x * 1000);
	rasterized_points.y = (int)(normalized_points.y * 1000);
	//printf("Rasterized Coords   (%d,%d)\n", rasterized_points.x, rasterized_points.y);
	return (rasterized_points);
}
