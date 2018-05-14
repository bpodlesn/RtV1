	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:20:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/08 18:03:06 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			key(t_main main)
{
	const Uint8	*keykey;

	keykey = SDL_GetKeyboardState(NULL);

	SDL_PollEvent(&main.sdl.event);
	main.sdl.event.type == SDL_QUIT ? exit (0) : 0;
	main.sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		exit (0) : 0;
	return (main);
}

t_main			create_sdl(t_main main)
{
	main.sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	Uint32 render_flags;
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	main.sdl.rend = SDL_CreateRenderer(main.sdl.win, -1, render_flags);
	main.sdl.fillscreen = SDL_CreateTexture(main.sdl.rend, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WINW, WINH);
	return (main);
}

t_main	canvastoviewport(int x, int y, t_main main)
{
	main.dir.dir.x = x * main.viewport.view.x / WINW;
	main.dir.dir.y = y * main.viewport.view.y / WINH;
	main.dir.dir.z = 1;
	return (main);
}

t_main		intersect_ray(t_main main, int i)
{
	double x[9];
	double result[3];
	double discriminant;
	main.t1 = INFINITY;
	main.t2 = INFINITY;

	result[0] = dot(main.dir.dir, main.dir.dir);
	x[3] = 2 * ((main.cam.cam.x - main.sphere[i].pos.x) * main.dir.dir.x);
	x[4] = 2 * ((main.cam.cam.y - main.sphere[i].pos.y) * main.dir.dir.y);
	x[5] = 2 * ((main.cam.cam.z - main.sphere[i].pos.z) * main.dir.dir.z);
	result[1] = (x[3] + x[4] + x[5]);
	x[6] = ((main.cam.cam.x - main.sphere[i].pos.x) * (main.cam.cam.x - main.sphere[i].pos.x)) - pow(main.sphere[i].radius, 2);// * main.sphere[i].radius);
	x[7] = ((main.cam.cam.y - main.sphere[i].pos.y) * (main.cam.cam.y - main.sphere[i].pos.y)) - pow(main.sphere[i].radius, 2);// * main.sphere[i].radius);
	x[8] = ((main.cam.cam.z - main.sphere[i].pos.z) * (main.cam.cam.z - main.sphere[i].pos.z)) - pow(main.sphere[i].radius, 2);// * main.sphere[i].radius);
	result[2] = x[6] + x[7] + x[8];
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}

double	find_vect_lenght(t_vector vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

t_main	find_l(t_main main, int i1)
{
	main.l.x = main.light[i1].pos.x - main.p.x;
	main.l.y = main.light[i1].pos.y - main.p.y;
	main.l.z = main.light[i1].pos.z - main.p.z;
	return (main);
}

t_main	find_r(t_main main)
{
	main.r.x = 2 * main.normal.x * dot(main.normal, main.l) - main.l.x;
	main.r.y = 2 * main.normal.y * dot(main.normal, main.l) - main.l.y;
	main.r.z = 2 * main.normal.z * dot(main.normal, main.l) - main.l.z;
	return (main);
}

double	compute_light(t_main main, int spec)
{
	double j = 0.0;
	int    i1 = 0;
	double n_dot;
	double r_dot;

	while (i1 < 3)
	{
		if (ft_strcmp(main.light[i1].type, "ambient") == 0)
			j += main.light[i1].intensivity;
		else
		{
			if (ft_strcmp(main.light[i1].type, "point") == 0)
				main = find_l(main, i1);
			else
			{
				main.l.x = main.light[i1].dir.x;
				main.l.y = main.light[i1].dir.y;
				main.l.z = main.light[i1].dir.z;
			}
			n_dot = dot(main.normal, main.l);
			if (n_dot > 0)
				j += main.light[i1].intensivity * n_dot / (find_vect_lenght(main.normal) * find_vect_lenght(main.l));
			if (spec != -1)
			{
				main = find_r(main);
				main.v.x = main.dir.dir.x * -1;
				main.v.y = main.dir.dir.y * -1;
				main.v.z = main.dir.dir.z * -1;
				r_dot = dot(main.r, main.v);
				if (r_dot > 0)
					j += main.light[i1].intensivity * pow(r_dot / (find_vect_lenght(main.r) * find_vect_lenght(main.v)), spec);
			}
		}
		i1++;
	}
	return (j);
}

t_main	find_normale(t_main main, int i)
{
	main.normal.x = main.p.x - main.sphere[i].pos.x;
	main.normal.y = main.p.y - main.sphere[i].pos.y;
	main.normal.z = main.p.z - main.sphere[i].pos.z;
	main.normal.x = main.normal.x / find_vect_lenght(main.normal);
	main.normal.y = main.normal.y / find_vect_lenght(main.normal);
	main.normal.z = main.normal.z / find_vect_lenght(main.normal);
	return (main);
}

t_main	find_p(t_main main, double closest_t)
{
	main.p.x = main.cam.cam.x + (closest_t * main.dir.dir.x);
	main.p.y = main.cam.cam.y + (closest_t * main.dir.dir.y);
	main.p.z = main.cam.cam.z + (closest_t * main.dir.dir.z);
	return (main);
}

unsigned int 	return_col(t_main main, double comp_light, int closest_sphere)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if ((unsigned int)(main.sphere[closest_sphere].color.r * comp_light) > 255)
		r = 255;
	else
		r = (unsigned int)(main.sphere[closest_sphere].color.r * comp_light);
	if ((unsigned int)(main.sphere[closest_sphere].color.g * comp_light) > 255)
		g = 255;
	else
		g = (unsigned int)(main.sphere[closest_sphere].color.g * comp_light);
	if ((unsigned int)(main.sphere[closest_sphere].color.b * comp_light) > 255)
		b = 255;
	else
		b = (unsigned int)(main.sphere[closest_sphere].color.b * comp_light);
	return ((r << 16) + (g << 8) + b);
}

unsigned int	sphere_color(t_main main, int t_min, double t_max)
{
	double closest_t = INFINITY;
	int closest_sphere = -1;
	int i = 0;
	double comp_light;

	while (i < 4)
	{
		main = intersect_ray(main, i);
		if (main.t1 > t_min && main.t1 < t_max && main.t1 < closest_t)
		{
			closest_t = main.t1;
			closest_sphere = i;
		}
		if (main.t2 > t_min && main.t2 < t_max && main.t2 < closest_t)
		{
			closest_t = main.t2;
			closest_sphere = i;
		}
		i++;
	}
	if (closest_sphere == -1)
		return (0);
	main = find_p(main, closest_t);
	main = find_normale(main, closest_sphere);
	comp_light = compute_light(main, main.sphere[closest_sphere].spec);

	return (return_col(main, comp_light, closest_sphere));	
}

void	update_screen(t_main main)
{
	int x;
	int y;
	int j;

	y = 0;
	j = 0;
	while(y < WINH)
	{
		x = 0;
		while(x < WINW)
		{
			main = canvastoviewport(x - (WINW / 2), (WINH / 2) - y, main);
			main.screencolor[j] = sphere_color(main, 1, INFINITY);
			j++;
			x++;
		}
		y++;
	}
	SDL_UpdateTexture(main.sdl.fillscreen, NULL, main.screencolor, WINW * 4);
	SDL_SetRenderDrawColor(main.sdl.rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(main.sdl.rend, main.sdl.fillscreen, NULL,
	NULL);
	SDL_RenderPresent(main.sdl.rend);
	SDL_RenderClear(main.sdl.rend);
}

void	set_viewport_params_and_cam(t_main *main)
{
	main->viewport.view.x = 1;
	main->viewport.view.y = 1;
	main->viewport.view.z = 1;
	main->cam.cam.x = 0;
	main->cam.cam.y = 0;
	main->cam.cam.z = -5;
	main->screencolor = malloc(sizeof(int) * (WINH * WINW));
}

t_main	set_spheres_params(t_main main)
{
	main.sphere[0].pos.x = 0;
	main.sphere[0].pos.y = -1;
	main.sphere[0].pos.z = 3;
	main.sphere[0].radius = 1;
	main.sphere[0].color.r = 255;
	main.sphere[0].color.g = 0;
	main.sphere[0].color.b = 0;
	main.sphere[0].spec = 1000;

	main.sphere[1].pos.x = 2;
	main.sphere[1].pos.y = 0;
	main.sphere[1].pos.z = 4;
	main.sphere[1].radius = 1;
	main.sphere[1].color.r = 0;
	main.sphere[1].color.g = 0;
	main.sphere[1].color.b = 255;
	main.sphere[1].spec = 500;

	main.sphere[2].pos.x = -2;
	main.sphere[2].pos.y = 0;
	main.sphere[2].pos.z = 4;
	main.sphere[2].radius = 1;
	main.sphere[2].color.r = 0;
	main.sphere[2].color.g = 255;
	main.sphere[2].color.b = 0;
	main.sphere[2].spec = 10000;

	main.sphere[3].pos.x = 0;
	main.sphere[3].pos.y = -8;
	main.sphere[3].pos.z = 22;
	main.sphere[3].radius = 5;
	main.sphere[3].color.r = 255;
	main.sphere[3].color.g = 255;
	main.sphere[3].color.b = 0;
	main.sphere[3].spec = 0;
	return (main);
}

t_main	lighter(t_main main)
{
	main.light[0].type = ft_strdup("point");
	main.light[0].intensivity = 0.6;
	main.light[0].pos.x = 2;
	main.light[0].pos.y = 1;
	main.light[0].pos.z = 0;
	main.light[1].type = ft_strdup("ambient");
	main.light[1].intensivity = 0.2;
	main.light[2].type = ft_strdup("directional");
	main.light[2].intensivity = 0.2;
	main.light[2].dir.x = 1;
	main.light[2].dir.y = 4;
	main.light[2].dir.z = 4;
	return (main);
}

void	rtv(t_main main)
{
	main = create_sdl(main);
	set_viewport_params_and_cam(&main);
	main.sphere = malloc(sizeof(t_sphere) * 4);
	main.light = malloc(sizeof(t_light) * 3);
	main = set_spheres_params(main);
	main = lighter(main);
	int i = 0;
	while(!main.done)
	{
		if (i == 0)
		{
			update_screen(main);
			i = 1;
		}
		main = key(main);
	}
}

int	main(int argc, char **argv)
{
	t_main	main;

	main.done = 0;
	(void)argv;
	if (argc == 1)
		rtv(main);
	else
		ft_putendl("You dont need args.");
	return (0);
}
