/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:05:46 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:06:27 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		dot(t_vector first, t_vector second)
{
	double	x[3];
	double	result;

	x[0] = first.x * second.x;
	x[1] = first.y * second.y;
	x[2] = first.z * second.z;
	result = x[0] + x[1] + x[2];
	return (result);
}

double		find_vect_lenght(t_vector vec)
{
	return (sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0)));
}

void		normalize(t_vector *vector)
{
	double	length;
	double	inv;

	length = find_vect_lenght((*vector));
	inv = 1 / length;
	mult_vect(vector, inv);
}
