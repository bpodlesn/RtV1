/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:01:19 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 15:47:46 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_1(t_main *main)
{
	main->li = 3;
	main->light = malloc(sizeof(t_light) * 3);
	main->light[0].type = ft_strdup("ambient");
	main->light[0].intensivity = 0.2;
	main->light[1].type = ft_strdup("point");
	main->light[1].intensivity = 0.4;
	update(&main->light[1].pos, -10, 0, 0);
	main->light[2].type = ft_strdup("point");
	main->light[2].intensivity = 0.4;
	update(&main->light[2].pos, 10, 0, 0);
}

t_main	scene_1(t_main main)
{
	main.counter = 16;
	main.figure = malloc(sizeof(t_figure) * 15);
	main.figure[0].type = ft_strdup("plane");
	update(&main.figure[0].pos, 0, -2, 12);
	update(&main.figure[0].dir, 0, 0, 1);
	update_color(&main.figure[0].color, 0, 150, 250);
	main.figure[0].spec = 1000.0;
	main.figure[1].type = ft_strdup("plane");
	update(&main.figure[1].pos, 0, 4.6, 1);
	update_color(&main.figure[1].color, 80, 80, 80);
	main.figure[1].spec = 1000.0;
	update(&main.figure[1].dir, 0, 4, 1);
	main.figure[2].type = ft_strdup("plane");
	update(&main.figure[2].pos, 0, -4.6, 1);
	update_color(&main.figure[2].color, 200, 0, 0);
	main.figure[2].spec = 1000.0;
	update(&main.figure[2].dir, 0, -4, 1);
	main = set_cylinder_params(main);
	main = set_spheres_params(main);
	main = set_spheres_params_2(main);
	return (main);
}

t_main	set_spheres_params(t_main main)
{
	main.figure[3].type = ft_strdup("sphere");
	main.figure[3].radius = 0.8;
	main.figure[3].spec = 1000.0;
	update(&main.figure[3].pos, -2, -1.9, 12.1);
	update_color(&main.figure[3].color, 200, 200, 200);
	main.figure[6].type = ft_strdup("sphere");
	main.figure[6].radius = 0.8;
	main.figure[6].spec = 1000.0;
	update(&main.figure[6].pos, 2, -1.9, 12.1);
	update_color(&main.figure[6].color, 200, 200, 200);
	main.figure[7].type = ft_strdup("sphere");
	main.figure[7].radius = 0.8;
	main.figure[7].spec = 1000.0;
	update(&main.figure[7].pos, -2, 1.9, 12.1);
	update_color(&main.figure[7].color, 200, 200, 200);
	main.figure[8].type = ft_strdup("sphere");
	main.figure[8].radius = 0.8;
	main.figure[8].spec = 1000.0;
	update(&main.figure[8].pos, 2, 1.9, 12.1);
	update_color(&main.figure[8].color, 200, 200, 200);
	main.figure[11].type = ft_strdup("sphere");
	main.figure[11].radius = 0.8;
	main.figure[11].spec = 1000.0;
	return (main);
}

t_main	set_spheres_params_2(t_main main)
{
	update(&main.figure[11].pos, -2.5, 2.8, 8);
	update_color(&main.figure[11].color, 200, 200, 200);
	main.figure[12].type = ft_strdup("sphere");
	main.figure[12].radius = 0.8;
	main.figure[12].spec = 1000.0;
	update(&main.figure[12].pos, 2.5, 2.8, 8);
	update_color(&main.figure[12].color, 200, 200, 200);
	main.figure[13].type = ft_strdup("sphere");
	main.figure[13].radius = 0.8;
	main.figure[13].spec = 1000.0;
	update(&main.figure[13].pos, -2.5, -2.8, 8);
	update_color(&main.figure[13].color, 200, 200, 200);
	main.figure[14].type = ft_strdup("sphere");
	main.figure[14].radius = 0.8;
	main.figure[14].spec = 1000.0;
	update(&main.figure[14].pos, 2.5, -2.8, 8);
	update_color(&main.figure[14].color, 200, 200, 200);
	main.figure[15].type = ft_strdup("sphere");
	main.figure[15].radius = 0.8;
	main.figure[15].spec = 1000.0;
	update(&main.figure[15].pos, 0, -1, 9);
	update_color(&main.figure[15].color, 200, 0, 200);
	return (main);
}

t_main	set_cylinder_params(t_main main)
{
	main.figure[5].type = ft_strdup("cylinder");
	main.figure[5].spec = 1000.0;
	main.figure[5].radius = 0.5;
	update(&main.figure[5].pos, -2, 0, 12);
	update_color(&main.figure[5].color, 255, 255, 255);
	update(&main.figure[5].dir, 0, 1, 0);
	main.figure[4].type = ft_strdup("cylinder");
	main.figure[4].spec = 1000;
	main.figure[4].radius = 0.5;
	update(&main.figure[4].pos, 2, 0, 12);
	update_color(&main.figure[4].color, 255, 255, 255);
	update(&main.figure[4].dir, 0, 1, 0);
	main.figure[9].type = ft_strdup("cylinder");
	main.figure[9].spec = 1000.0;
	main.figure[9].radius = 0.5;
	update(&main.figure[9].pos, 2.5, 0, 8);
	update_color(&main.figure[9].color, 255, 255, 255);
	update(&main.figure[9].dir, 0, 1, 0);
	main.figure[10].type = ft_strdup("cylinder");
	main.figure[10].spec = 1000.0;
	main.figure[10].radius = 0.5;
	update(&main.figure[10].pos, -2.5, 0, 8);
	update_color(&main.figure[10].color, 255, 255, 255);
	update(&main.figure[10].dir, 0, 1, 0);
	return (main);
}
