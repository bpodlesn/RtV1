/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:58:54 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/08 16:04:21 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	dot(t_vector first, t_vector second)
{
	double x[3];
	double result;

	x[0] = first.x * second.x;
	x[1] = first.y * second.y;
	x[2] = first.z * second.z;
	result = x[0] + x[1] + x[2];
	return (result);
}

void	minus_vect(t_vector first, t_vector second, t_vector *result)
{
	result->x = first.x - second.x;
	result->y = first.y - second.y;
	result->z = first.z - second.z;
}

void	plus_vect(t_vector first, t_vector second, t_vector *result)
{
	result->x = first.x + second.x;
	result->y = first.y + second.y;
	result->z = first.z + second.z;
}

double	find_vect_lenght(t_vector vec)
{
	return (sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0)));
}

void	rewrite_vect_and_mult(t_vector *first, t_vector second, double i)
{
	first->x = second.x * i;
	first->y = second.y * i;
	first->z = second.z * i;
}

void	mult_vect(t_vector *first, double i)
{
	first->x *= i;
	first->y *= i;
	first->z *= i;
}

void 	div_vect(t_vector *first, double i)
{
	first->x /= i;
	first->y /= i;
	first->z /= i;
}

void	rewrite_vect_and_div(t_vector *first, t_vector second, double i)
{
	first->x = second.x / i;
	first->y = second.y / i;
	first->z = second.z / i;
}

void	rewrite_vect(t_vector *first, t_vector second)
{
	first->x = second.x;
	first->y = second.y;
	first->z = second.z;
}

void	normalize(t_vector *vector)
{
	double length;
	double inv;

	length = find_vect_lenght((*vector));
	inv = 1 / length;
	mult_vect(vector, inv);
}
