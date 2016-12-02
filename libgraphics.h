/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:59:14 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 22:45:51 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GRAPHICS_H
# define LIB_GRAPHICS_H
#include "libft.h"
#include "mlx.h"
#include <math.h>

#include <stdio.h> ///REMOVE

typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct	s_vec2f
{
	float		x;
	float		y;
}				t_vec2f;

typedef struct	s_vec3f
{
	float		x;
	float		y;
	float		z;
}				t_vec3f;

typedef struct	s_vec6f
{
	t_vec3f		position;
	t_vec3f		rotation;
}				t_vec6f;

typedef struct	s_3d_object
{
	int			*faces_arr;
	int			face_cnt;
	int			*vertex_ind;
	t_vec3f		*vertices;
	int			vertex_cnt;
	t_vec6f		pos_vector;

	void		(*transform)(struct	s_3d_object obj);
}				t_3d_object;

typedef struct  s_camera
{
	t_vec6f		loc;
	t_vec3f		viewer;
}				t_camera;

typedef struct	s_scene
{
	t_vec3f		origin_point;
	t_camera	*camera;
	t_list		*objects;

	t_vec2f		(*projection_method)(struct s_scene scene,
										t_vec3f point);
}				t_scene;

typedef struct	s_renderer
{
	void		*mlx;
	void		*window;
	t_scene		*scene;

	void		(*render)(struct s_renderer renderer, t_scene scene);
}				t_renderer;

t_vec2i			*new_vec2i(int x, int y);
t_vec2f			*new_vec2f(float x, float y);
t_vec3f			*new_vec3f(float x, float y, float z);
t_vec6f			*new_vec6f(t_vec3f pos, t_vec3f rot);
t_3d_object		*new_3d_object(char *filename);
t_camera		*new_camera(t_vec6f camera_loc, t_vec3f viewer_loc);
t_scene			*new_scene(t_vec2f (*projection)(t_scene scene, t_vec3f point));
t_renderer		*new_renderer(void (*render)(struct s_renderer, t_scene));
void			del_3d_object(t_3d_object *obj);
void			del_scene(t_scene *scene);
void			del_renderer(t_renderer *renderer);
t_vec2f			perspective_projection(t_scene scene, t_vec3f point);
//t_vec2i			orthographic_projection(t_scene scene, t_vec3f point);
void			translate(t_3d_object *obj, t_vec3f translation);
void			rotate(t_3d_object *obj, t_vec3f rotation);
t_3d_object		update_verticies(t_3d_object *obj);
void			drawline(t_renderer renderer, t_vec2f point_a, t_vec2f point_b);
void			drawline3d(t_renderer renderer, t_vec3f point_a, t_vec3f point_b);
void			render3d_object(t_renderer renderer, t_3d_object obj);
void			render_scene(t_renderer renderer, t_scene scene);
void			add_object(t_scene *scene, t_3d_object *obj);
void			rem_object(t_scene *scene, t_3d_object *obj);
t_vec2i			vec2i(int x, int y);
t_vec2f			vec2f(float x, float y);
t_vec3f			vec3f(float x, float y, float z);
t_vec6f			vec6f(t_vec3f pos, t_vec3f rot);
t_camera		camera(t_vec6f camera_loc, t_vec3f viewer_loc);
t_scene			scene(t_vec2f (*projection)(t_scene scene, t_vec3f point));
t_renderer		renderer(void (*render)(struct s_renderer, t_scene));

#endif
