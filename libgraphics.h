/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:59:14 by cyildiri          #+#    #+#             */
/*   Updated: 2016/11/21 16:22:20 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_3d_vector	pos_vector;

	void		(*transform)(struct	s_3d_object obj);
}				t_3d_object;

typedef struct	s_3d_scene
{
	t_3d_vector *eye_relative_canvas;
	t_3d_vector *cameras_vectors;
	int			camera_cnt;
	t_vec3f		origin_point;
	t_3d_object *objects;
	int			object_cnt;

	void		(*projection_method)(struct s_3d_scene scene);
}				t_3d_scene;

typedef struct	s_renderer
{
	void		*mlx;
	void		*windows;
	int			window_cnt;
	t_3d_scene 	*scenes;
	int			scenes_cnt;

	void		(*render)(struct	s_renderer renderer, t_3d_scene scene);
}				t_renderer;
