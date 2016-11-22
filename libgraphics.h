/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:59:14 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 21:53:33 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GRAPHICS_H
# define LIB_GRAPHICS_H
#include "libft.h"

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

typedef struct  s_vec6f
{
    t_vec3f     position;
    t_vec3f     rotation;
}               t_vec6f;

typedef struct	s_3d_object
{
	int			*faces_arr;
	int			face_cnt;
	int			*vertex_ind;
	t_vec3f		*vertices;
	t_vec6f		pos_vector;

	void		(*transform)(struct	s_3d_object obj);
}				t_3d_object;

typedef struct  s_camera
{
    t_vec6f     cam_loc;
	t_vec3f		viewer_loc;
}               t_camera;

typedef struct	s_scene
{
    t_vec3f     origin_point;
	t_camera	*cameras;
	int			camera_cnt;
	t_3d_object *objects;
	int			object_cnt;

	void		(*projection_method)(struct s_3d_scene scene);
}				t_scene;

typedef struct	s_renderer
{
	void		*mlx;
	void		*windows;
	int			window_cnt;
	t_scene 	*scenes;
	int			scenes_cnt;

	void		(*render)(struct	s_renderer renderer, t_3d_scene scene);
}				t_renderer;

t_vec2i			*new_vec2i(int x, int y);
t_vec2f			*new_vec2f(float x, float y);
t_vec3f			*new_vec3f(float x, float y, float z);
t_vec6f			*new_vec6f(t_vec3f pos, t_vec3f rot);
t_3d_object		*new_3d_object(char	*filename);
t_camera		*new_camera(t_vec6f camera_loc, t_vec3f viewer_loc);
t_scene			*new_scene(void (*projection_method)(struct s_scene));
t_renderer		*new_renderer(void (*render)(struct s_renderer, t_scene));
t_vec2i			perspective_projection(t_scene *scene, t_vec3f point);
t_vec2i			orthographic_projection(t_scene *scene, t_vec3f point);
t_vec6f			transalate(vec6f *obj_vector, vec3f translation);
t_vec6f			rotate(vec6f *obj_vector, vec3f rotation);
t_3d_object		updateVerticies(t_3d_object *obj);
void			drawline(t_renderer renderer, vec2f point_a, vec2f point_b);
void			drawline3d(t_renderer renderer, vec3f point_a, vec3f point_b);
void			render3d_object(t_renderer renderer, t_3d_object obj, int mode);
void			render_scene(t_renderer renderer, t_scene scene);
void			render_all_scenes(t_renderer renderer);
void			add_object(t_scene	*scene, t_3d_object *obj);
void			rem_object(t_scene *scene, t_3d_object *obj);
void			add_camera(t_scene *scene, t_vec6f *camera_loc,
							t_vec6f viewer_loc);
void 			rem_camera(t_scene *scene, t_vec6f *camera_loc,
							t_vec6f viewer_loc);
void 			add_scene(t_renderer *renderer, t_scene *scene);
void 			rem_scene(t_renderer *renderer, t_scene *scene);
void			add_window(t_renderer *renderer, int height, int width,
							char *name);
void			rem_window(t_renderer *renderer, char *name);
t_vec2i			vec2i(int x, int y);
t_vec2f			vec2f(float x, float y);
t_vec3f			vec3f(float x, float y, float z);
t_vec6f 		vec6f(t_vec3f pos, t_vec3f rot);
t_3d_object		new_camera(t_vec6f camera_loc, t_vec3f viewer_loc);

#endif
