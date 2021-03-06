/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:20:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/30 17:40:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			create_sdl(t_main main)
{
	Uint32		render_flags;

	main.sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	main.sdl.rend = SDL_CreateRenderer(main.sdl.win, -1, render_flags);
	main.sdl.fillscreen = SDL_CreateTexture(main.sdl.rend,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WINW, WINH);
	return (main);
}

t_main			canvastoviewport(int x, int y, t_main main)
{
	main.dir.dir.x = x * main.viewport.view.x / WINW;
	main.dir.dir.y = y * main.viewport.view.y / WINH;
	main.dir.dir.z = 1;
	return (main);
}

void			set_viewport_params_and_cam(t_main *main)
{
	main->viewport.view.x = 1;
	main->viewport.view.y = 1;
	main->viewport.view.z = 1;
	main->cam.cam.x = 0;
	main->cam.cam.y = 0;
	main->cam.cam.z = -5;
	main->screencolor = malloc(sizeof(int) * (WINH * WINW) + 1);
}

void			rtv(t_main main, char *av)
{
	main = create_sdl(main);
	set_viewport_params_and_cam(&main);
	main = set_figures_params(main, av);
	if (ft_strcmp("1", av) == 0)
		light_1(&main);
	else if (ft_strcmp("2", av) == 0)
		light_2(&main);
	else if (ft_strcmp("3", av) == 0)
		light_3(&main);
	else if (ft_strcmp("4", av) == 0)
		light_4(&main);
	else
	{
		ft_putendl("Choose scene (1, 2, 3, 4)");
		main.done = 1;
	}
	main.go = 0;
	while (!main.done)
	{
		if (main.go == 0)
		{
			update_screen(main);
			main.go = 1;
		}
		main = key(main);
	}
}

int				main(int argc, char **argv)
{
	t_main		main;

	main.done = 0;
	if (argc == 2)
		rtv(main, argv[1]);
	else
		ft_putendl("Choose scene (1, 2, 3, 4).");
	return (0);
}
