/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:19:12 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/25 14:19:23 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
