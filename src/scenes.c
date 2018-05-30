/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:22:30 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 16:05:48 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	update(t_vector *v, double a, double b, double c)
{
	v->x = a;
	v->y = b;
	v->z = c;
}

void	update_color(t_color *v, int a, int b, int c)
{
	a > 255 ? a = 255 : 0;
	a < 0 ? a = 0 : 0;
	b > 255 ? b = 255 : 0;
	b < 0 ? b = 0 : 0;
	c > 255 ? c = 255 : 0;
	c < 0 ? c = 0 : 0;
	v->r = a;
	v->g = b;
	v->b = c;
}

t_main	set_figures_params(t_main main, char *str)
{
	if (ft_strcmp("1", str) == 0)
		main = scene_1(main);
	if (ft_strcmp("2", str) == 0)
		main = scene_2(main);
	if (ft_strcmp("3", str) == 0)
		main = scene_3(main);
	if (ft_strcmp("4", str) == 0)
		main = scene_4(main);
	return (main);
}
