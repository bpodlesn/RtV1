/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_prims.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:17:53 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:01:40 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			intersect_ray(t_main main, t_vector v1, t_vector v2, double rad)
{
	double		result[3];
	double		discriminant;

	main.t1 = INFINITY;
	main.t2 = INFINITY;
	result[0] = dot(v1, v1);
	result[1] = 2 * dot(v2, v1);
	result[2] = dot(v2, v2) - pow(rad, 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}

double			calc_plane(t_main main, t_vector x, int i)
{
	t_vector	v;
	double		t;

	rewrite_vect(&v, FDIR);
	normalize(&v);
	mult_vect(&x, -1.0);
	t = dot(x, v) / dot(DIR, v);
	mult_vect(&v, -1.0);
	rewrite_vect(&main.normal, v);
	return (t);
}

t_main			cylinder_ray(t_main main, double radius, int i, int k)
{
	double		result[3];
	double		discriminant;
	t_vector	v;

	if (k == 0)
	{
		rewrite_vect(&v, DIR);
		minus_vect(main.cam.cam, POS, &OC);
	}
	else
	{
		rewrite_vect(&v, main.l);
		minus_vect(main.p, POS, &OC);
	}
	normalize(&FDIR);
	result[0] = dot(v, v) - pow(dot(v, FDIR), 2);
	result[1] = 2 * (dot(v, OC) - (dot(v, FDIR) * dot(OC, FDIR)));
	result[2] = dot(OC, OC) - pow(dot(OC, FDIR), 2) - pow(radius, 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}

t_main			cone_ray(t_main main, int i, int k)
{
	double		discriminant;
	double		result[3];
	t_vector	v;

	k == 0 ? rewrite_vect(&v, DIR) : rewrite_vect(&v, main.l);
	k == 0 ? minus_vect(main.cam.cam, POS, &OC) : minus_vect(main.p, POS, &OC);
	normalize(&FDIR);
	main.k = tan((main.figure[i].angle / 2) * PI / 180);
	result[0] = dot(DIR, DIR) - (1 + pow(main.k, 2)) * pow(dot(DIR, FDIR), 2);
	result[1] = 2 * (dot(DIR, OC) - (1 + pow(main.k, 2)) *
		dot(DIR, FDIR) * (dot(OC, FDIR)));
	result[2] = dot(OC, OC) - (1 + pow(main.k, 2)) * pow(dot(OC, FDIR), 2);
	discriminant = pow(result[1], 2) - (4 * result[0] * result[2]);
	if (discriminant < 0)
		return (main);
	main.t1 = (-result[1] + sqrt(discriminant)) / (2 * result[0]);
	main.t2 = (-result[1] - sqrt(discriminant)) / (2 * result[0]);
	return (main);
}
