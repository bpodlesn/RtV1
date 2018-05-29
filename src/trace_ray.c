/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:08:26 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:09:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			chk_closest_t(t_main main, double *cl_t, int *cl_fig, int i)
{
	if (main.t1 > T_MIN && main.t1 < T_MAX && main.t1 < (*cl_t))
	{
		(*cl_t) = main.t1;
		(*cl_fig) = i;
	}
	if (main.t2 > T_MIN && main.t2 < T_MAX && main.t2 < (*cl_t))
	{
		(*cl_t) = main.t2;
		(*cl_fig) = i;
	}
}

void			cl_t_and_fig(t_main main, double *cl_t, int *cl_fig, int i)
{
	double		cl_pl;

	T_MIN = 1;
	T_MAX = INFINITY;
	while (++i < main.counter)
	{
		minus_vect(main.cam.cam, POS, &OC);
		if (ft_strcmp("sphere", TYPE) == 0)
			main = intersect_ray(main, main.dir.dir, OC, RADIUS);
		else if (ft_strcmp("plane", TYPE) == 0)
		{
			cl_pl = calc_plane(main, OC, i);
			if (cl_pl > T_MIN && cl_pl < T_MAX && cl_pl < (*cl_t))
			{
				(*cl_t) = cl_pl;
				(*cl_fig) = i;
			}
			continue ;
		}
		else if (ft_strcmp("cylinder", TYPE) == 0)
			main = cylinder_ray(main, RADIUS, i, 0);
		else if (ft_strcmp("cone", TYPE) == 0)
			main = cone_ray(main, i, 0);
		chk_closest_t(main, cl_t, cl_fig, i);
	}
}

int				cl_t_s_fig(t_main main, int i, double s_t, int s_fig)
{
	double		cl_pl;

	T_MIN = 0.001;
	T_MAX = 1;
	while (++i < main.counter)
	{
		ft_strcmp("sphere", TYPE) == 0 ? minus_vect(main.p, POS, &OC) : 0;
		ft_strcmp("sphere", TYPE) == 0 ?
			main = intersect_ray(main, L, OC, RADIUS) : main;
		if (ft_strcmp("plane", TYPE) == 0)
		{
			cl_pl = calc_plane(main, OC, i);
			cl_pl > T_MIN && cl_pl < T_MAX && cl_pl < (s_t) ? s_t = cl_pl : 0;
			cl_pl > T_MIN && cl_pl < T_MAX && cl_pl < (s_t) ? s_fig = i : 0;
			continue ;
		}
		else if (ft_strcmp("cylinder", TYPE) == 0)
			main = cylinder_ray(main, RADIUS, i, 1);
		else if (ft_strcmp("cone", TYPE) == 0)
			main = cone_ray(main, i, 1);
		chk_closest_t(main, &s_t, &s_fig, i);
	}
	return (s_fig);
}

double			specular(t_main main, double j, int i, double spec)
{
	double		r_dot;

	main = find_r(main);
	rewrite_vect(&main.v, main.dir.dir);
	mult_vect(&main.v, -1.0);
	r_dot = dot(main.r, main.v);
	r_dot > 0 ? j += main.light[i].intensivity * (double)pow(r_dot
		/ (find_vect_lenght(main.r) * find_vect_lenght(main.v)), spec) : 0;
	return (j);
}

double			compute_light(t_main main, int spec, double j, int i1)
{
	double		n_dot;
	int			shadow_figure;

	while (++i1 < 3)
	{
		shadow_figure = -1;
		if (ft_strcmp(main.light[i1].type, "ambient") == 0)
			j += main.light[i1].intensivity;
		else
		{
			minus_vect(main.light[i1].pos, main.p, &main.l);
			T_MAX = 1;
			shadow_figure = cl_t_s_fig(main, -1, INFINITY, -1);
			if (shadow_figure != -1)
				continue ;
			n_dot = dot(main.normal, main.l);
			n_dot > 0 ? j += (main.light[i1].intensivity * n_dot) /
				(find_vect_lenght(main.normal) * find_vect_lenght(main.l)) : 0;
			spec != -1 ? j = specular(main, j, i1, spec) : 0;
		}
	}
	return (j);
}
