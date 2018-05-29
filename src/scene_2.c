/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:12:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:11:01 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main	scene_2(t_main main)
{
	main.counter = 5;
	main.figure = malloc(sizeof(t_figure) * 5);
	main.figure[0].type = ft_strdup("cone");
	main.figure[0].pos.x = 0;
	main.figure[0].pos.y = 0;
	main.figure[0].pos.z = 20;
	main.figure[0].radius = 1;
	main.figure[0].color.r = 0;
	main.figure[0].color.g = 150;
	main.figure[0].color.b = 250;
	main.figure[0].spec = 1000.0;
	main.figure[0].dir.x = 1;
	main.figure[0].dir.y = 0;
	main.figure[0].dir.z = 0;
	main.figure[0].angle = 50;
	main.figure[1].type = ft_strdup("cone");
	main.figure[1].pos.x = 0;
	main.figure[1].pos.y = 0;
	main.figure[1].pos.z = 20;
	main.figure[1].radius = 1;
	main.figure[1].color.r = 255;
	main.figure[1].color.g = 150;
	main.figure[1].color.b = 250;
	main.figure[1].spec = 1000.0;
	main.figure[1].dir.x = 0;
	main.figure[1].dir.y = 1;
	main.figure[1].dir.z = 0;
	main.figure[1].angle = 50;
	main = scene_2_1(main);
	return (main);
}

t_main scene_2_1(t_main main)
{
	main.figure[2].type = ft_strdup("cone");
	main.figure[2].pos.x = 0;
	main.figure[2].pos.y = 0;
	main.figure[2].pos.z = 20;
	main.figure[2].radius = 1;
	main.figure[2].color.r = 255;
	main.figure[2].color.g = 100;
	main.figure[2].color.b = 100;
	main.figure[2].spec = 1000.0;
	main.figure[2].dir.x = 1;
	main.figure[2].dir.y = 1;
	main.figure[2].dir.z = 0;
	main.figure[2].angle = 50;
	main.figure[3].type = ft_strdup("cone");
	main.figure[3].pos.x = 0;
	main.figure[3].pos.y = 0;
	main.figure[3].pos.z = 20;
	main.figure[3].radius = 0.5;
	main.figure[3].color.r = 0;
	main.figure[3].color.g = 150;
	main.figure[3].color.b = 0;
	main.figure[3].spec = 1000.0;
	main.figure[3].dir.x = -1;
	main.figure[3].dir.y = 1;
	main.figure[3].dir.z = 0;
	main.figure[3].angle = 50;
	main.figure[4].type = ft_strdup("sphere");
	main.figure[4].pos.x = 0;
	main.figure[4].pos.y = 0;
	main.figure[4].pos.z = 5;
	main.figure[4].radius = 1;
	main.figure[4].color.r = 255;
	main.figure[4].color.g = 255;
	main.figure[4].color.b = 255;
	main.figure[4].spec = 1000.0;
	return (main);
}
