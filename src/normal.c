/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:51:31 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 16:19:15 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			normale_cone_cyl(t_main main, int i)
{
	t_vector	a;
	t_vector	v;
	double		m;
	double		dist;

	if (main.t1 > main.t2)
		dist = main.t2;
	else
		dist = main.t1;
	minus_vect(main.p, main.figure[i].pos, &a);
	m = dot(main.dir.dir, main.figure[i].dir) * dist +
		dot(a, main.figure[i].dir);
	rewrite_vect(&v, main.figure[i].dir);
	mult_vect(&v, m);
	minus_vect(a, v, &main.normal);
	if (ft_strcmp(main.figure[i].type, "cone") == 0)
	{
		mult_vect(&v, m * pow(main.k, 2));
		minus_vect(main.normal, v, &main.normal);
	}
	normalize(&main.normal);
	return (main);
}

t_main			find_normale(t_main main, int i)
{
	if (ft_strcmp(main.figure[i].type, "sphere") == 0)
	{
		minus_vect(main.p, main.figure[i].pos, &main.normal);
		div_vect(&main.normal, find_vect_lenght(main.normal));
	}
	else if (ft_strcmp(main.figure[i].type, "plane") == 0)
	{
		rewrite_vect(&main.normal, main.figure[i].dir);
		mult_vect(&main.normal, -1.0);
	}
	else if (ft_strcmp(main.figure[i].type, "cylinder") == 0
		|| ft_strcmp(main.figure[i].type, "cone") == 0)
		main = normale_cone_cyl(main, i);
	return (main);
}

t_main			find_r(t_main main)
{
	main.r.x = 2.0 * main.normal.x * dot(main.normal, main.l) - main.l.x;
	main.r.y = 2.0 * main.normal.y * dot(main.normal, main.l) - main.l.y;
	main.r.z = 2.0 * main.normal.z * dot(main.normal, main.l) - main.l.z;
	return (main);
}

t_main			find_p(t_main main, double closest_t)
{
	main.p.x = main.cam.cam.x + (closest_t * main.dir.dir.x);
	main.p.y = main.cam.cam.y + (closest_t * main.dir.dir.y);
	main.p.z = main.cam.cam.z + (closest_t * main.dir.dir.z);
	return (main);
}
