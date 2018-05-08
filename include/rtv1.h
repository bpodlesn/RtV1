/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:21:02 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/08 18:45:21 by bpodlesn         ###   ########.fr       */
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
# define HALF_WINW 400
# define HALF_WINH 800 
# define VIEW_W 1
# define VIEW_H 1
# define D 1

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*texture;
	SDL_Event		event;
}				t_sdl;

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

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

typedef	struct	s_sphere
{
	t_vector	pos;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_ray_dir
{
	t_vector	dir;
}				t_ray_dir;

typedef struct	s_main
{
	int			done;
	t_sphere	*sphere;
	t_cam		cam;
	t_sdl		sdl;
	t_ray_dir	dir;
	t_viewport	viewport;
	double		t1;
	double		t2;
}				t_main;

#endif
