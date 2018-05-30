/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:27:05 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 17:57:56 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_3(t_main *main)
{
	main->li = 2;
	main->light = malloc(sizeof(t_light) * 2);
	main->light[0].type = ft_strdup("ambient");
	main->light[0].intensivity = 0.2;
	main->light[1].type = ft_strdup("point");
	main->light[1].intensivity = 0.9;
	update(&main->light[1].pos, 3, -0.8, 1);
}

t_main	scene_3(t_main main)
{
	main.counter = 5;
	main.figure = malloc(sizeof(t_figure) * 5);
	main.figure[0].type = ft_strdup("plane");
	update(&main.figure[0].pos, 0, -2, 20);
	update_color(&main.figure[0].color, 0, 150, 250);
	update(&main.figure[0].dir, 0, 0, 1);
	main.figure[0].spec = 1000.0;
	main.figure[1].type = ft_strdup("plane");
	update(&main.figure[1].pos, 0, -0.8, 1);
	update_color(&main.figure[1].color, 255, 0, 0);
	update(&main.figure[1].dir, 0, -2, 0);
	main.figure[1].spec = 1000.0;
	main.figure[1].angle = 50;
	main = scene_3_1(main);
	return (main);
}

t_main	scene_3_1(t_main main)
{
	main.figure[2].type = ft_strdup("cone");
	update(&main.figure[2].pos, 0, 2, 1);
	update_color(&main.figure[2].color, 255, 100, 100);
	update(&main.figure[2].dir, 0.5, 2, 0);
	main.figure[2].radius = 1;
	main.figure[2].spec = 1000.0;
	main.figure[2].angle = 50;
	main.figure[3].type = ft_strdup("cylinder");
	update(&main.figure[3].pos, 2, -1, 1);
	update_color(&main.figure[3].color, 0, 150, 0);
	update(&main.figure[3].dir, -1, 1, 0);
	main.figure[3].radius = 0.3;
	main.figure[3].spec = 1000.0;
	main.figure[4].type = ft_strdup("sphere");
	update(&main.figure[4].pos, 3, 2, 5);
	update_color(&main.figure[4].color, 255, 255, 0);
	main.figure[4].radius = 1;
	main.figure[4].spec = 10;
	return (main);
}
