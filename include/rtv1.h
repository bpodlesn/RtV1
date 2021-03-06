/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:21:02 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 16:44:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdbool.h>
# include <SDL_image.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/src/libft.h"
# define WINW 800
# define WINH 800
# define HALF_WINW WINW / 2
# define HALF_WINH WINH / 2
# define VIEW_W 1
# define VIEW_H 1
# define D 1
# define PI 3.14159265359
# define TYPE main.figure[i].type
# define POS main.figure[i].pos
# define RADIUS main.figure[i].radius
# define FDIR main.figure[i].dir
# define DIR main.dir.dir
# define T_MIN main.t_min
# define T_MAX main.t_max
# define OC main.oc
# define L main.l

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*fillscreen;
	SDL_Surface		*surf;
	SDL_Event		event;
}				t_sdl;

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_light
{
	char		*type;
	double		intensivity;
	t_vector	pos;
}				t_light;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_cam
{
	t_vector	cam;
}				t_cam;

typedef	struct	s_viewport
{
	t_vector	view;
}				t_viewport;

typedef	struct	s_figure
{
	char		*type;
	t_vector	pos;
	double		radius;
	t_color		color;
	double		spec;
	t_vector	dir;
	int			angle;
}				t_figure;

typedef struct	s_ray_dir
{
	t_vector	dir;
}				t_ray_dir;

typedef struct	s_main
{
	int			done;
	t_light		*light;
	t_figure	*figure;
	t_vector	normal;
	t_cam		cam;
	t_sdl		sdl;
	t_ray_dir	dir;
	t_vector	oc;
	t_vector	l;
	t_vector	p;
	t_vector	r;
	t_vector	v;
	t_viewport	viewport;
	double		t1;
	double		t2;
	double		t_min;
	double		t_max;
	double		closest_t;
	int			closest_sphere;
	int			go;
	int			*screencolor;
	int			shadow;
	double		dist;
	int			counter;
	double		k;
	int			li;
}				t_main;

double			dot(t_vector first, t_vector second);
void			minus_vect(t_vector first, t_vector second, t_vector *result);
void			plus_vect(t_vector first, t_vector second, t_vector *result);
double			find_vect_lenght(t_vector vec);
void			rewrite_vect(t_vector *first, t_vector second);
void			mult_vect(t_vector *first, double i);
void			div_vect(t_vector *first, double i);
void			update_screen(t_main main);
void			cl_t_and_fig(t_main main, double *cl_t, int *cl_fig, int i);
double			compute_light(t_main main, int spec, double j, int i1);
t_main			key(t_main main);
t_main			create_sdl(t_main main);
t_main			canvastoviewport(int x, int y, t_main main);
t_main			find_r(t_main main);
t_main			find_normale(t_main main, int i);
t_main			find_p(t_main main, double closest_t);
void			set_viewport_params_and_cam(t_main *main);
t_main			set_figures_params(t_main main, char *str);
t_main			set_plane_params(t_main main);
void			light_1(t_main *main);
void			light_2(t_main *main);
void			light_3(t_main *main);
void			rtv(t_main main, char *av);
void			normalize(t_vector *vector);
t_main			scene_1(t_main main);
t_main			set_spheres_params(t_main main);
t_main			set_spheres_params_2(t_main main);
t_main			set_cylinder_params(t_main main);
t_main			scene_2(t_main main);
void			update_screen(t_main main);
t_main			intersect_ray(t_main main, t_vector v1, t_vector v2,
				double rad);
double			calc_plane(t_main main, t_vector x, int i, int k);
t_main			cylinder_ray(t_main main, double radius, int i, int k);
unsigned int	return_col(t_main main, double comp_light, int closest_sphere);
unsigned int	what_color(t_main main);
t_main			cone_ray(t_main main, int i, int k);
t_main			scene_2_1(t_main main);
void			update(t_vector *v, double a, double b, double c);
void			update_color(t_color *v, int a, int b, int c);
t_main			scene_3(t_main main);
t_main			scene_3_1(t_main main);
void			light_4(t_main *main);
t_main			scene_4(t_main main);
t_main	scene_4_1(t_main main);

#endif
