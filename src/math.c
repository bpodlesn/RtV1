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