/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:08:26 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/16 18:58:23 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main		intersect_ray(t_main main, t_vector vector1, t_vector vector2, double radius)
{
	double result[3];
	double discriminant;
	main.t1 = INFINITY;
	main.t2 = INFINITY;
	// main.oc = 


	result[0] = dot(vector1, vector1);
	result[1] = 2*dot(vector2, vector1);
	result[2] = dot(vector2, vector2) - pow(radius, 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}

double		calc_plane(t_main main, t_vector p, t_vector c, t_vector x)
{
	t_vector	v;
	double 		t;

	minus_vect(p, c, &v);
	mult_vect(&x, -1);
	t = dot(x, v) / dot(main.dir.dir, v);
	return (t);
}

t_main		cylinder_ray(t_main main, t_vector c, double radius, int i)
{
	double	result[3];
	double	discriminant;
	double	m;
	main.t1 = INFINITY;
	main.t2 = INFINITY;
	t_vector	v;
	t_vector	a;
	t_vector	l;


	// minus_vect(main.cam.cam, main.figure[i].pos, &main.oc);
	minus_vect(main.p, c, &v);
	plus_vect(main.c, )
	result[0] = dot(main.dir.dir, main.dir.dir) - pow(dot(main.dir.dir, v),2);
	result[1] = 2 * (dot(main.dir.dir, main.oc) - (dot(main.dir.dir, v) * (dot(main.oc, v))));
	result[2] = dot(main.oc, main.oc) - pow(dot(main.oc, v),2) - pow(radius, 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	m = dot(main.dir.dir, v) * main.t2 + dot(main.oc, v);
	minus_vect(main.p, main.figure[i].pos, &main.normal);
	mult_vect(&v, -m);
	minus_vect(main.normal, v, &main.normal);
	div_vect(&main.normal, find_vect_lenght(main.normal));
	return (main);
}

void			closest_t_and_sphere(t_main main, double *closest_t, int *closest_sphere, int t_min, double t_max)
{
	int i;

	i = 0;
	double closest_plane;

	while (i < 6)
	{
		minus_vect(main.cam.cam, main.figure[i].pos, &main.oc);
		if (ft_strcmp("sphere", main.figure[i].type) == 0)
			main = intersect_ray(main, main.dir.dir, main.oc, main.figure[i].radius);
		else if (ft_strcmp("plane", main.figure[i].type) == 0)
		{
			closest_plane = calc_plane(main, main.p, main.figure[i].pos, main.oc);
			if (closest_plane > t_min && closest_plane < t_max && closest_plane < (*closest_t))
			{
				(*closest_t) = closest_plane;
				(*closest_sphere) = i;
			}
			i++;
			continue ;
		}
		else if (ft_strcmp("cylinder", main.figure[i].type) == 0)
		{
			main = cylinder_ray(main, main.figure[i].pos, main.figure[i].radius, i);
		}
		if (main.t1 > t_min && main.t1 < t_max && main.t1 < (*closest_t))
		{
			(*closest_t) = main.t1;
			(*closest_sphere) = i;
		}
		if (main.t2 > t_min && main.t2 < t_max && main.t2 < (*closest_t))
		{
			(*closest_t) = main.t2;
			(*closest_sphere) = i;
		}
		i++;
	}
}

int			closest_t_and_shadow_sphere(t_main main, int shadow_sphere, int closest_sphere, double t_max)
{
	int i;
	double t_min = 0.001;

	i = 0;
	double shadow_t = INFINITY;
	closest_sphere = 1;

	while (i < 4)
	{
		if (ft_strcmp("sphere", main.figure[i].type) == 0)
		{
			minus_vect(main.p, main.figure[i].pos, &main.oc);
			main = intersect_ray(main, main.l, main.oc, main.figure[i].radius);
		}
		if (main.t1 > t_min && main.t1 < t_max && main.t1 < (shadow_t))
		{
			(shadow_t) = main.t1;
			(shadow_sphere) = i;
		}
		if (main.t2 > t_min && main.t2 < t_max && main.t2 < (shadow_t))
		{
			(shadow_t) = main.t2;
			(shadow_sphere) = i;
		}
		i++;
	}
	return (shadow_sphere);
}

double	compute_light(t_main main, int spec, int closest_sphere)
{
	double j = 0.0;
	int    i1 = 0;
	double n_dot;
	double r_dot;
	double t_max = INFINITY;
	int shadow_sphere = -1;
	// double	shadow_t = INFINITY;
	closest_sphere = 2;

	while (i1 < 4)
	{
		if (ft_strcmp(main.light[i1].type, "ambient") == 0)
			j += main.light[i1].intensivity;
		else
		{
			if (ft_strcmp(main.light[i1].type, "point") == 0)
			{
				minus_vect(main.light[i1].pos, main.p, &main.l); // find L
				t_max = 1;
			}
			else
			{
				rewrite_vect(&main.l, main.light[i1].dir);
				t_max = INFINITY;
			}
			n_dot = dot(main.normal, main.l);

			// shadow_sphere = closest_t_and_shadow_sphere(main, shadow_sphere, closest_sphere, t_max);
			// printf("%d\n", shadow_sphere);
			if (shadow_sphere == -1)
			{
				if (n_dot > 0)
					j += main.light[i1].intensivity * n_dot / (find_vect_lenght(main.normal) * find_vect_lenght(main.l));
				if (spec != -1)
				{
					main = find_r(main);
					rewrite_vect(&main.v, main.dir.dir);
					mult_vect(&main.v, -1.0);
					r_dot = dot(main.r, main.v);
					if (r_dot > 0)
						j += main.light[i1].intensivity * pow(r_dot / (find_vect_lenght(main.r) * find_vect_lenght(main.v)), spec);
				}
			}
		}
		i1++;
	}
	return (j);
}

unsigned int 	return_col(t_main main, double comp_light, int closest_sphere)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if ((unsigned int)(main.figure[closest_sphere].color.r * comp_light) > 255)
		r = 255;
	else
		r = (unsigned int)(main.figure[closest_sphere].color.r * comp_light);
	if ((unsigned int)(main.figure[closest_sphere].color.g * comp_light) > 255)
		g = 255;
	else
		g = (unsigned int)(main.figure[closest_sphere].color.g * comp_light);
	if ((unsigned int)(main.figure[closest_sphere].color.b * comp_light) > 255)
		b = 255;
	else
		b = (unsigned int)(main.figure[closest_sphere].color.b * comp_light);
	return ((r << 16) + (g << 8) + b);
}

unsigned int	sphere_color(t_main main, int t_min, double t_max)
{
	double closest_t = INFINITY;
	int closest_sphere = -1;
	double comp_light;

	closest_t_and_sphere(main, &closest_t, &closest_sphere, t_min, t_max);
	if (closest_sphere == -1)
		return (0);
	main = find_p(main, closest_t);
	main = find_normale(main, closest_sphere);
	comp_light = compute_light(main, main.figure[closest_sphere].spec, closest_sphere);
	return (return_col(main, comp_light, closest_sphere));	
}

void	update_screen(t_main main)
{
	int x;
	int y;
	int j;

	y = -1;
	j = 0;
	while(++y < WINH)
	{
		x = -1;
		while(++x < WINW)
		{
			main = canvastoviewport(x - (WINW / 2), (WINH / 2) - y, main);
			main.screencolor[j] = sphere_color(main, 1, INFINITY);
			j++;
		}
	}
	SDL_UpdateTexture(main.sdl.fillscreen, NULL, main.screencolor, WINW * 4);
	SDL_SetRenderDrawColor(main.sdl.rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(main.sdl.rend, main.sdl.fillscreen, NULL,
	NULL);
	SDL_RenderPresent(main.sdl.rend);
	SDL_RenderClear(main.sdl.rend);
}
