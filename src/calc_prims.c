/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_prims.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:17:53 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/25 14:18:15 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main		intersect_ray(t_main main, t_vector vector1, t_vector vector2, double radius)
{
	double result[3];
	double discriminant;
	main.t1 = INFINITY;
	main.t2 = INFINITY;

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

double		calc_plane(t_main main, t_vector x, int i)
{
	t_vector	v;
	double 		t;

	rewrite_vect(&v, main.figure[i].dir);
	normalize(&v);
	mult_vect(&x, -1.0);
	t = dot(x, v) / dot(main.dir.dir, v);
	mult_vect(&v, -1.0);
	rewrite_vect(&main.normal, v);
	return (t);
}

t_main		cylinder_ray(t_main main, double radius, int i, int k)
{
	double	result[3];
	double	discriminant;
	t_vector v;

	if (k == 0)
	{
		rewrite_vect(&v, main.dir.dir);
		minus_vect(main.cam.cam, main.figure[i].pos, &main.oc);
	}
	else
	{
		rewrite_vect(&v, main.l);
		minus_vect(main.p, main.figure[i].pos, &main.oc);
	}
	normalize(&main.figure[i].dir);
	result[0] = dot(v, v) - pow(dot(v, main.figure[i].dir), 2);
	result[1] = 2 * (dot(v, main.oc) - (dot(v, main.figure[i].dir) * dot(main.oc, main.figure[i].dir)));
	result[2] = dot(main.oc, main.oc) - pow(dot(main.oc, main.figure[i].dir), 2) - pow(radius, 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}

t_main		cone_ray(t_main main, int i)
{
	// t_vector a;
	double discriminant;
	double result[3];

	main.k = tan((main.figure[i].angle / 2) * PI / 180);
	result[0] = dot(main.dir.dir, main.dir.dir) - (1 + pow(main.k, 2)) * pow(dot(main.dir.dir, main.figure[i].dir), 2);
	result[1] = 2 * (dot(main.dir.dir, main.oc) - (1 + pow(main.k, 2)) * dot(main.dir.dir, main.figure[i].dir) * (dot(main.oc, main.figure[i].dir)));
	result[2] = dot(main.oc, main.oc) - (1 + pow(main.k, 2)) * pow(dot(main.oc, main.figure[i].dir), 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}
