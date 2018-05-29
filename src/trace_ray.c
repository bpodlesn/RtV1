/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:08:26 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/25 15:56:43 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


t_main	find_normale(t_main main, int i)
{
	t_vector a;
	t_vector v;
	double	 m;
	double	 dist;

	if (ft_strcmp(main.figure[i].type, "sphere") == 0)
	{
		minus_vect(main.p, main.figure[i].pos, &main.normal);
		div_vect(&main.normal, find_vect_lenght(main.normal));
	}
	else if (ft_strcmp(main.figure[i].type, "plane")  == 0)
	{
		rewrite_vect(&main.normal, main.figure[i].dir);
		mult_vect(&main.normal, -1.0);
	}
	else if (ft_strcmp(main.figure[i].type, "cylinder") == 0)
	{
		if (main.t1 > main.t2)
			dist = main.t2;
		else
			dist = main.t1;
		minus_vect(main.p, main.figure[i].pos, &a);
		m = dot(main.dir.dir, main.figure[i].dir) * dist + dot(a, main.figure[i].dir);
		rewrite_vect(&v, main.figure[i].dir);
		mult_vect(&v, m);
		minus_vect(a, v, &main.normal);
		normalize(&main.normal);
	}
	else if (ft_strcmp(main.figure[i].type, "cone") == 0)
	{
		if (main.t1 > main.t2)
			dist = main.t2;
		else
			dist = main.t1;
		minus_vect(main.p, main.figure[i].pos, &a);
		m = dot(main.dir.dir, main.figure[i].dir) * dist + dot(a, main.figure[i].dir);
		rewrite_vect(&v, main.figure[i].dir);
		mult_vect(&v, m);
		minus_vect(a, v, &main.normal);
		mult_vect(&v, m*main.k*main.k);
		minus_vect(main.normal, v, &main.normal);
		normalize(&main.normal);
	}
	return (main);
}

void			closest_t_and_sphere(t_main main, double *closest_t, int *closest_sphere, int t_min, double t_max)
{
	int i;

	i = 0;
	double closest_plane;

	while (i < main.counter)
	{
		minus_vect(main.cam.cam, main.figure[i].pos, &main.oc);
		if (ft_strcmp("sphere", main.figure[i].type) == 0)
			main = intersect_ray(main, main.dir.dir, main.oc, main.figure[i].radius);
		else if (ft_strcmp("plane", main.figure[i].type) == 0)
		{
			closest_plane = calc_plane(main, main.oc, i);
			if (closest_plane > t_min && closest_plane < t_max && closest_plane < (*closest_t))
			{
				(*closest_t) = closest_plane;
				(*closest_sphere) = i;
			}
			i++;
			continue ;
		}
		else if (ft_strcmp("cylinder", main.figure[i].type) == 0)
			main = cylinder_ray(main, main.figure[i].radius, i, 0);
		else if (ft_strcmp("cone", main.figure[i].type) == 0)
			main = cone_ray(main, i);
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
	double	closest_plane;

	i = 0;
	double shadow_t = INFINITY;
	closest_sphere = 1;

	while (i < main.counter)
	{
		if (ft_strcmp("sphere", main.figure[i].type) == 0)
		{
			minus_vect(main.p, main.figure[i].pos, &main.oc);
			main = intersect_ray(main, main.l, main.oc, main.figure[i].radius);
		}
		else if (ft_strcmp("plane", main.figure[i].type) == 0)
		{
			closest_plane = calc_plane(main, main.oc, i);
			if (closest_plane > t_min && closest_plane < t_max && closest_plane < (shadow_t))
			{
				(shadow_t) = closest_plane;
				(shadow_sphere) = i;
			}
			i++;
			continue ;
		}
		else if (ft_strcmp("cylinder", main.figure[i].type) == 0)
			main = cylinder_ray(main, main.figure[i].radius, i, 1);
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
	double t_max = 1;
	int shadow_sphere;
	closest_sphere = 1;

	while (i1 < 3)
	{
		shadow_sphere = -1;
		if (ft_strcmp(main.light[i1].type, "ambient") == 0)
			j += main.light[i1].intensivity;
		else
		{
			minus_vect(main.light[i1].pos, main.p, &main.l); // find L
			shadow_sphere = closest_t_and_shadow_sphere(main, shadow_sphere, closest_sphere, t_max);
			if (shadow_sphere != -1 && i1++ > -1)
				continue;
			n_dot = dot(main.normal, main.l);
			if (n_dot > 0)
				j += (main.light[i1].intensivity * n_dot) / (find_vect_lenght(main.normal) * find_vect_lenght(main.l));
			if (spec != -1)
			{
				main = find_r(main);
				rewrite_vect(&main.v, main.dir.dir);
				mult_vect(&main.v, -1.0);
				r_dot = dot(main.r, main.v);
				if (r_dot > 0)
					j += main.light[i1].intensivity * (double)pow(r_dot / (find_vect_lenght(main.r) * find_vect_lenght(main.v)), spec);
			}
		}
		i1++;
	}
	return (j);
}

unsigned int	what_color(t_main main, int t_min, double t_max)
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
