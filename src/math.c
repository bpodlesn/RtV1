/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:58:54 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:07:36 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

void	mult_vect(t_vector *first, double i)
{
	first->x *= i;
	first->y *= i;
	first->z *= i;
}

void	div_vect(t_vector *first, double i)
{
	first->x /= i;
	first->y /= i;
	first->z /= i;
}

void	rewrite_vect(t_vector *first, t_vector second)
{
	first->x = second.x;
	first->y = second.y;
	first->z = second.z;
}
