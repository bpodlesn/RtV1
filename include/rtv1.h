/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:21:02 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/16 17:56:44 by bpodlesn         ###   ########.fr       */
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
	t_vector	dir;
}				t_light;

typedef struct	s_color
{
	int 		r;
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
	int			spec;
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
	double		closest_t;
	int			closest_sphere;
	int 		go;
	int			*screencolor;
	int 		shadow;
}				t_main;


double	dot(t_vector first, t_vector second);
void	minus_vect(t_vector first, t_vector second, t_vector *result);
double	find_vect_lenght(t_vector vec);
void	rewrite_vect_and_mult(t_vector *first, t_vector second, double i);
void	rewrite_vect_and_div(t_vector *first, t_vector second, double i);
void	rewrite_vect(t_vector *first, t_vector second);
void	mult_vect(t_vector *first, double i);
void 	div_vect(t_vector *first, double i);
void	update_screen(t_main main);
t_main	key(t_main main);
t_main	create_sdl(t_main main);
t_main	canvastoviewport(int x, int y, t_main main);
t_main	find_r(t_main main);
t_main	find_normale(t_main main, int i);
t_main	find_p(t_main main, double closest_t);
void	set_viewport_params_and_cam(t_main *main);
t_main	set_figures_params(t_main main);
t_main	set_plane_params(t_main main);
t_main	lighter(t_main main);
void	rtv(t_main main);
#endif
