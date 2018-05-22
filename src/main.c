/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:20:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/08 18:03:06 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_main			key(t_main main)
{
	const Uint8	*keykey;

	keykey = SDL_GetKeyboardState(NULL);

	SDL_PollEvent(&main.sdl.event);
	main.sdl.event.type == SDL_QUIT ? main.done = 1 : 0;
	main.sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		main.done = 1 : 0;
	if (keykey[SDL_SCANCODE_UP])
	{
		main.cam.cam.y += 0.1;
		main.go = 0;
	}
	if (keykey[SDL_SCANCODE_DOWN])
	{
		main.cam.cam.y -= 0.1;
		main.go = 0;
	}
	if (keykey[SDL_SCANCODE_LEFT])
	{
		main.cam.cam.x -= 0.1;
		main.go = 0;
	}
	if (keykey[SDL_SCANCODE_RIGHT])
	{
		main.cam.cam.x += 0.1;
		main.go = 0;
	}
	if (keykey[SDL_SCANCODE_W])
	{
		main.cam.cam.z += 0.1;
		main.go = 0;
	}
	if (keykey[SDL_SCANCODE_S])
	{
		main.cam.cam.z -= 0.1;
		main.go = 0;
	}
	return (main);
}

t_main			create_sdl(t_main main)
{
	main.sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	Uint32 render_flags;
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	main.sdl.rend = SDL_CreateRenderer(main.sdl.win, -1, render_flags);
	main.sdl.fillscreen = SDL_CreateTexture(main.sdl.rend, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WINW, WINH);
	return (main);
}

t_main	canvastoviewport(int x, int y, t_main main)
{
	main.dir.dir.x = x * main.viewport.view.x / WINW;
	main.dir.dir.y = y * main.viewport.view.y / WINH;
	main.dir.dir.z = 1;
	return (main);
}

// t_main	find_l(t_main main, int i1)
// {
	
// 	return (main);
// }

t_main	find_r(t_main main)
{
	main.r.x = 2 * main.normal.x * dot(main.normal, main.l) - main.l.x;
	main.r.y = 2 * main.normal.y * dot(main.normal, main.l) - main.l.y;
	main.r.z = 2 * main.normal.z * dot(main.normal, main.l) - main.l.z;
	return (main);
}

t_main	find_normale(t_main main, int i)
{
	minus_vect(main.p, main.figure[i].pos, &main.normal);
	div_vect(&main.normal, find_vect_lenght(main.normal));
	return (main);
}

t_main	find_p(t_main main, double closest_t)
{
	main.p.x = main.cam.cam.x + (closest_t * main.dir.dir.x);
	main.p.y = main.cam.cam.y + (closest_t * main.dir.dir.y);
	main.p.z = main.cam.cam.z + (closest_t * main.dir.dir.z);
	return (main);
}

void	set_viewport_params_and_cam(t_main *main)
{
	main->viewport.view.x = 1;
	main->viewport.view.y = 1;
	main->viewport.view.z = 1;
	main->cam.cam.x = 0;
	main->cam.cam.y = 0;
	main->cam.cam.z = -100;
	main->screencolor = malloc(sizeof(int) * (WINH * WINW));
}

t_main	set_figures_params(t_main main)
{
	main.figure[0].type = ft_strdup("sphere");
	main.figure[0].pos.x = 0;
	main.figure[0].pos.y = -1;
	main.figure[0].pos.z = 3;
	main.figure[0].radius = 1;
	main.figure[0].color.r = 255;
	main.figure[0].color.g = 0;
	main.figure[0].color.b = 0;
	main.figure[0].spec = 10;

	main.figure[1].type = ft_strdup("sphere");
	main.figure[1].pos.x = -2;
	main.figure[1].pos.y = 1;
	main.figure[1].pos.z = 3;
	main.figure[1].radius = 1;
	main.figure[1].color.r = 0;
	main.figure[1].color.g = 0;
	main.figure[1].color.b = 255;
	main.figure[1].spec = 500;

	main.figure[2].type = ft_strdup("sphere");
	main.figure[2].pos.x = 2;
	main.figure[2].pos.y = 1;
	main.figure[2].pos.z = 3;
	main.figure[2].radius = 1;
	main.figure[2].color.r = 0;
	main.figure[2].color.g = 255;
	main.figure[2].color.b = 0;
	main.figure[2].spec = 1000;

	main.figure[3].type = ft_strdup("sphere");
	main.figure[3].pos.x = 0;
	main.figure[3].pos.y = 0;
	main.figure[3].pos.z = 3;
	main.figure[3].radius = 1;
	main.figure[3].color.r = 255;
	main.figure[3].color.g = 255;
	main.figure[3].color.b = 0;
	main.figure[3].spec = 1000;
	main = set_plane_params(main);
	return (main);
}

t_main	set_plane_params(t_main main)
{
	main.figure[4].type = ft_strdup("plane");
	main.figure[4].pos.x = 0;
	main.figure[4].pos.y = 1;
	main.figure[4].pos.z = 5;
	main.figure[4].color.r = 100;
	main.figure[4].color.g = 0;
	main.figure[4].color.b = 255;
	main.figure[4].spec = 1000;
	//cylinder
	main.figure[5].type = ft_strdup("cylinder");
	main.figure[5].pos.x = 1;
	main.figure[5].pos.y = 2;
	main.figure[5].pos.z = 1;
	main.figure[5].color.r = 100;
	main.figure[5].color.g = 20;
	main.figure[5].color.b = 100;
	main.figure[5].spec = 1000;
	main.figure[5].radius = 1;
	return (main);
}

t_main	lighter(t_main main)
{
	main.light[0].type = ft_strdup("ambient");
	main.light[0].intensivity = 0.2;
	main.light[1].type = ft_strdup("point");
	main.light[1].intensivity = 0.6;
	main.light[1].pos.x = 2;
	main.light[1].pos.y = 1;
	main.light[1].pos.z = 0;
	main.light[2].type = ft_strdup("directional");
	main.light[2].intensivity = 0.2;
	main.light[2].pos.x = 1;
	main.light[2].pos.y = 4;
	main.light[2].pos.z = 2;
	main.light[3].type = ft_strdup("directional");
	main.light[3].intensivity = 0.2;
	main.light[3].dir.x = 1;
	main.light[3].dir.y = 4;
	main.light[3].dir.z = 2;
	return (main);
}

void	rtv(t_main main)
{
	main = create_sdl(main);
	set_viewport_params_and_cam(&main);
	main.figure = malloc(sizeof(t_figure) * 6);
	main.light = malloc(sizeof(t_light) * 4);
	main = set_figures_params(main);
	main = lighter(main);
	main.go = 0;
	while(!main.done)
	{
		if (main.go == 0)
		{
			update_screen(main);
			main.go = 1;
		}
		main = key(main);
	}
}

int	main(int argc, char **argv)
{
	t_main	main;

	main.done = 0;
	(void)argv;
	if (argc == 1)
		rtv(main);
	else
		ft_putendl("You dont need args.");
	return (0);
}
