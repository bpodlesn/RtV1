/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:53:46 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 16:14:54 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_4(t_main *main)
{
	main->li = 2;
	main->light = malloc(sizeof(t_light) * 2);
	main->light[0].type = ft_strdup("ambient");
	main->light[0].intensivity = 0.2;
	main->light[1].type = ft_strdup("point");
	main->light[1].intensivity = 0.8;
	update(&main->light[1].pos, 0, 0, -1);
}

t_main	scene_4(t_main main)
{
	main.counter = 6;
	main.figure = malloc(sizeof(t_figure) * 6);
	main.figure[0].type = ft_strdup("sphere");
	update(&main.figure[0].pos, 0, 0.65, 0);
	update_color(&main.figure[0].color, 0, 150, 250);
	main.figure[0].radius = 0.7;
	main.figure[0].spec = 1000.0;
	main.figure[1].type = ft_strdup("sphere");
	update(&main.figure[1].pos, -1, -1, 0);
	update_color(&main.figure[1].color, 255, 150, 250);
	main.figure[1].spec = 1000.0;
	main.figure[1].radius = 0.7;
	main.figure[2].type = ft_strdup("sphere");
	update(&main.figure[2].pos, 1, -1, 0);
	update_color(&main.figure[2].color, 150, 150, 50);
	main.figure[2].spec = 1000.0;
	main.figure[2].radius = 0.7;
	main = scene_4_1(main);
	return (main);
}

t_main	scene_4_1(t_main main)
{
	main.figure[3].type = ft_strdup("cylinder");
	update(&main.figure[3].pos, 1, -1, 0);
	update_color(&main.figure[3].color, 150, 0, 50);
	update(&main.figure[3].dir, -0.6, 1, 0);
	main.figure[3].radius = 0.3;
	main.figure[3].spec = 1000.0;
	main.figure[4].type = ft_strdup("cylinder");
	update(&main.figure[4].pos, -1, -1, 0);
	update_color(&main.figure[4].color, 50, 150, 50);
	update(&main.figure[4].dir, 0.6, 1, 0);
	main.figure[4].radius = 0.3;
	main.figure[4].spec = 1000.0;
	main.figure[5].type = ft_strdup("cylinder");
	update(&main.figure[5].pos, 0, -1, 0);
	update_color(&main.figure[5].color, 50, 0, 150);
	update(&main.figure[5].dir, 1, 0, 0);
	main.figure[5].radius = 0.3;
	main.figure[5].spec = 1000.0;
	return (main);
}
