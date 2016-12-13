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

#ifndef LIBGRAPHICS_H
# define LIBGRAPHICS_H

# include <math.h>
# include "libft.h"
# include "mlx.h"

typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct	s_vec2fc
{
	float		x;
	float		y;
	int			color;
}				t_vec2fc;

typedef struct	s_vec3fc
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_vec3fc;

typedef struct	s_vec6f
{
	t_vec3fc	position;
	t_vec3fc	rotation;
}				t_vec6f;

typedef struct	s_3d_object
{
	int			*faces_arr;
	int			face_cnt;
	int			*vertex_ind;
	t_vec3fc	*vertices;
	int			vertex_cnt;
	t_vec6f		pos_vector;
	void		(*transform)(struct	s_3d_object obj);
}				t_3d_object;

typedef struct	s_camera
{
	t_vec6f		loc;
	t_vec3fc	viewer;
}				t_camera;

typedef struct	s_scene
{
	t_vec3fc	origin_point;
	t_camera	*camera;
	t_list		*objects;
	t_vec3fc	scale;
	t_vec3fc	(*projection_method)(struct s_scene scene,
										t_vec3fc point);
}				t_scene;

typedef struct	s_renderer
{
	void		*mlx;
	void		*window;
	int			win_x;
	int			win_y;
	t_scene		*scene;
	t_vec2fc	last_click;

	void		(*render)(struct s_renderer renderer, t_scene scene);
}				t_renderer;

t_vec2i			*new_vec2i(int x, int y);
t_vec2fc		*new_vec2f(float x, float y);
t_vec3fc		*new_vec3f(float x, float y, float z);
t_vec6f			*new_vec6f(t_vec3fc pos, t_vec3fc rot);
t_3d_object		*new_3d_object(char *filename);
t_camera		*new_camera(t_vec6f camera_loc, t_vec3fc viewer_loc);
t_scene			*new_scene(t_vec3fc (*projection)(t_scene scene, t_vec3fc point));
t_renderer		*new_renderer(void (*render)(struct s_renderer, t_scene));
void			del_3d_object(t_3d_object *obj);
void			del_scene(t_scene *scene);
void			del_renderer(t_renderer *renderer);
t_vec3fc		perspective_projection(t_scene scene, t_vec3fc point);
t_vec3fc		orthographic_projection(t_scene scene, t_vec3fc point);
t_vec3fc		translate_point(t_vec3fc original, t_vec3fc translation);
void			rotate_object(t_3d_object *obj, t_vec3fc rotation);
void			drawline(t_renderer renderer, t_vec3fc point_a, t_vec3fc point_b);
void			drawline3d(t_renderer renderer, t_vec3fc point_a,
							t_vec3fc point_b);
void			render3d_object(t_renderer renderer, t_3d_object obj);
void			render_scene(t_renderer renderer, t_scene scene);
void			add_object(t_scene *scene, t_3d_object *obj);
void			rem_object(t_scene *scene, t_3d_object *obj);
t_vec2i			vec2i(int x, int y);
t_vec2fc		vec2fc(float x, float y, int color);
t_vec2fc		vec2f(float x, float y);
t_vec3fc		vec3f(float x, float y, float z);
t_vec3fc		vec3fc(float x, float y, float z, int color);
t_vec6f			vec6f(t_vec3fc pos, t_vec3fc rot);
t_camera		camera(t_vec6f camera_loc, t_vec3fc viewer_loc);
t_scene			scene(t_vec3fc (*projection)(t_scene scene, t_vec3fc point));
t_renderer		renderer(void (*render)(struct s_renderer, t_scene));

#endif
