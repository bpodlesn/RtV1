/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:19:12 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 16:23:21 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int		return_col(t_main main, double comp_light, int cl_fig)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if ((unsigned int)(main.figure[cl_fig].color.r * comp_light) > 255)
		r = 255;
	else
		r = (unsigned int)(main.figure[cl_fig].color.r * comp_light);
	if ((unsigned int)(main.figure[cl_fig].color.g * comp_light) > 255)
		g = 255;
	else
		g = (unsigned int)(main.figure[cl_fig].color.g * comp_light);
	if ((unsigned int)(main.figure[cl_fig].color.b * comp_light) > 255)
		b = 255;
	else
		b = (unsigned int)(main.figure[cl_fig].color.b * comp_light);
	return ((r << 16) + (g << 8) + b);
}

unsigned int		what_color(t_main main)
{
	double			closest_t;
	int				closest_figure;
	double			comp_light;

	closest_t = INFINITY;
	closest_figure = -1;
	cl_t_and_fig(main, &closest_t, &closest_figure, -1);
	if (closest_figure == -1)
		return (0);
	main = find_p(main, closest_t);
	main = find_normale(main, closest_figure);
	comp_light = compute_light(main, closest_figure, 0.0, -1);
	return (return_col(main, comp_light, closest_figure));
}
