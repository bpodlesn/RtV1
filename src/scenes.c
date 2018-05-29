/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:22:30 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:18:51 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			lighter(t_main main)
{
	main.light[0].type = ft_strdup("ambient");
	main.light[0].intensivity = 0.2;
	main.light[1].type = ft_strdup("point");
	main.light[1].intensivity = 0.4;
	main.light[1].pos.x = 15;
	main.light[1].pos.y = 0;
	main.light[1].pos.z = 0;
	main.light[2].type = ft_strdup("point");
	main.light[2].intensivity = 0.4;
	main.light[2].pos.x = -15;
	main.light[2].pos.y = 0;
	main.light[2].pos.z = 0;
	main.light[3].type = ft_strdup("point");
	main.light[3].intensivity = 0.4;
	main.light[3].pos.x = 4;
	main.light[3].pos.y = -2;
	main.light[3].pos.z = 0;
	main.light[4].type = ft_strdup("point");
	main.light[4].intensivity = 0.4;
	main.light[4].pos.x = -4;
	main.light[4].pos.y = -2;
	main.light[4].pos.z = 0;
	return (main);
}

t_main	scene_1(t_main main)
{
	main.counter = 16;
	main.figure = malloc(sizeof(t_figure) * 15);
	main.figure[0].type = ft_strdup("plane");
	main.figure[0].pos.x = 0;
	main.figure[0].pos.y = -2;
	main.figure[0].pos.z = 12;
	main.figure[0].radius = 1;
	main.figure[0].color.r = 0;
	main.figure[0].color.g = 150;
	main.figure[0].color.b = 250;
	main.figure[0].spec = 1000.0;
	main.figure[0].dir.x = 0;
	main.figure[0].dir.y = 0;
	main.figure[0].dir.z = 1;

	main.figure[1].type = ft_strdup("plane");
	main.figure[1].pos.x = 0;
	main.figure[1].pos.y = 4.6;
	main.figure[1].pos.z = 1;
	main.figure[1].color.r = 80;
	main.figure[1].color.g = 80;
	main.figure[1].color.b = 80;
	main.figure[1].spec = 1000.0;
	main.figure[1].dir.x = 0;
	main.figure[1].dir.y = 4;
	main.figure[1].dir.z = 1;

	main.figure[2].type = ft_strdup("plane");
	main.figure[2].pos.x = 0;
	main.figure[2].pos.y = -4.6;
	main.figure[2].pos.z = 1;
	main.figure[2].color.r = 200;
	main.figure[2].color.g = 0;
	main.figure[2].color.b = 0;
	main.figure[2].spec = 1000.0;
	main.figure[2].dir.x = 0;
	main.figure[2].dir.y = -4;
	main.figure[2].dir.z = 1;
	main = set_plane_params(main);
	main = set_spheres_params(main);
	return (main);
}

t_main	set_figures_params(t_main main, char str)
{
	if (ft_strcmp("1", &str) == 0)
		main = scene_1(main);
	if (ft_strcmp("2", &str) == 0)
		main = scene_2(main);
	// if (ft_strcmp("2", &str) == 0)
	// 	main = scene_3(main);
	return (main);
}

t_main	set_spheres_params(t_main main)
{
	main.figure[3].type = ft_strdup("sphere");
	main.figure[3].pos.x = -2;
	main.figure[3].pos.y = -1.9;
	main.figure[3].pos.z = 12.1;
	main.figure[3].radius = 0.8;
	main.figure[3].color.r = 200;
	main.figure[3].color.g = 200;
	main.figure[3].color.b = 200;
	main.figure[3].spec = 1000.0;

	main.figure[6].type = ft_strdup("sphere");
	main.figure[6].pos.x = 2;
	main.figure[6].pos.y = -1.9;
	main.figure[6].pos.z = 12.1;
	main.figure[6].radius = 0.8;
	main.figure[6].color.r = 200;
	main.figure[6].color.g = 200;
	main.figure[6].color.b = 200;
	main.figure[6].spec = 1000.0;

	main.figure[7].type = ft_strdup("sphere");
	main.figure[7].pos.x = -2;
	main.figure[7].pos.y = 1.9;
	main.figure[7].pos.z = 12.1;
	main.figure[7].radius = 0.8;
	main.figure[7].color.r = 200;
	main.figure[7].color.g = 200;
	main.figure[7].color.b = 200;
	main.figure[7].spec = 1000.0;

	main.figure[8].type = ft_strdup("sphere");
	main.figure[8].pos.x = 2;
	main.figure[8].pos.y = 1.9;
	main.figure[8].pos.z = 12.1;
	main.figure[8].radius = 0.8;
	main.figure[8].color.r = 200;
	main.figure[8].color.g = 200;
	main.figure[8].color.b = 200;
	main.figure[8].spec = 1000.0;

	main.figure[11].type = ft_strdup("sphere");
	main.figure[11].pos.x = -2.5;
	main.figure[11].pos.y = 2.8;
	main.figure[11].pos.z = 8;
	main.figure[11].radius = 0.8;
	main.figure[11].color.r = 200;
	main.figure[11].color.g = 200;
	main.figure[11].color.b = 200;
	main.figure[11].spec = 1000.0;

	main.figure[12].type = ft_strdup("sphere");
	main.figure[12].pos.x = 2.5;
	main.figure[12].pos.y = 2.8;
	main.figure[12].pos.z = 8;
	main.figure[12].radius = 0.8;
	main.figure[12].color.r = 200;
	main.figure[12].color.g = 200;
	main.figure[12].color.b = 200;
	main.figure[12].spec = 1000.0;

	main.figure[13].type = ft_strdup("sphere");
	main.figure[13].pos.x = -2.5;
	main.figure[13].pos.y = -2.8;
	main.figure[13].pos.z = 8;
	main.figure[13].radius = 0.8;
	main.figure[13].color.r = 200;
	main.figure[13].color.g = 200;
	main.figure[13].color.b = 200;
	main.figure[13].spec = 1000.0;

	main.figure[14].type = ft_strdup("sphere");
	main.figure[14].pos.x = 2.5;
	main.figure[14].pos.y = -2.8;
	main.figure[14].pos.z = 8;
	main.figure[14].radius = 0.8;
	main.figure[14].color.r = 200;
	main.figure[14].color.g = 200;
	main.figure[14].color.b = 200;
	main.figure[14].spec = 1000.0;

	main.figure[15].type = ft_strdup("sphere");
	main.figure[15].pos.x = 0;
	main.figure[15].pos.y = -2;
	main.figure[15].pos.z = 9;
	main.figure[15].radius = 0.8;
	main.figure[15].color.r = 200;
	main.figure[15].color.g = 0;
	main.figure[15].color.b = 200;
	main.figure[15].spec = 1000.0;

	return (main);
}

t_main	set_plane_params(t_main main)
{

	//cylinder
	main.figure[5].type = ft_strdup("cylinder");
	main.figure[5].pos.x = -2;
	main.figure[5].pos.y = 0;
	main.figure[5].pos.z = 12;
	main.figure[5].color.r = 255;
	main.figure[5].color.g = 255;
	main.figure[5].color.b = 255;
	main.figure[5].spec = 1000.0;
	main.figure[5].radius = 0.5;
	main.figure[5].dir.x = 0;
	main.figure[5].dir.y = 1;
	main.figure[5].dir.z = 0;

	main.figure[4].type = ft_strdup("cone");
	main.figure[4].pos.x = 2;
	main.figure[4].pos.y = 0;
	main.figure[4].pos.z = 12;
	main.figure[4].color.r = 255;
	main.figure[4].color.g = 255;
	main.figure[4].color.b = 255;
	main.figure[4].spec = 1000;
	main.figure[4].radius = 0.5;
	main.figure[4].dir.x = 1;
	main.figure[4].dir.y = 1;
	main.figure[4].dir.z = 0;
	main.figure[4].angle = 40;

	main.figure[9].type = ft_strdup("cylinder");
	main.figure[9].pos.x = 2.5;
	main.figure[9].pos.y = 0;
	main.figure[9].pos.z = 8;
	main.figure[9].color.r = 255;
	main.figure[9].color.g = 255;
	main.figure[9].color.b = 255;
	main.figure[9].spec = 1000.0;
	main.figure[9].radius = 0.5;
	main.figure[9].dir.x = 0;
	main.figure[9].dir.y = 1;
	main.figure[9].dir.z = 0;

	main.figure[10].type = ft_strdup("cylinder");
	main.figure[10].pos.x = -2.5;
	main.figure[10].pos.y = 0;
	main.figure[10].pos.z = 8;
	main.figure[10].color.r = 255;
	main.figure[10].color.g = 255;
	main.figure[10].color.b = 255;
	main.figure[10].spec = 1000.0;
	main.figure[10].radius = 0.5;
	main.figure[10].dir.x = 0;
	main.figure[10].dir.y = 1;
	main.figure[10].dir.z = 0;
	return (main);
}
