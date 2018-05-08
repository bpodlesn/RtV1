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
	main.sdl.event.type == SDL_QUIT ? exit (0) : 0;
	main.sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		exit (0) : 0;
	return (main);
}

t_main			create_sdl(t_main main)
{
	main.sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	main.sdl.rend = SDL_CreateRenderer(main.sdl.win, -1, 0);
	//init CAM
	main.cam.cam.x = 0;
	main.cam.cam.y = 0;
	main.cam.cam.z = -20;
	return (main);
}

t_main	canvastoviewport(int x, int y, t_main main)
{
	main.dir.dir.x = x * main.viewport.view.x / WINW;
	main.dir.dir.y = y * main.viewport.view.y / WINH;
	main.dir.dir.z = 1;
	return (main);
}

t_main		intersect_ray(t_main main, int i)
{
	main.t1 = 0;
	main.t2 = 0;
	double x1;
	double x2;
	double x3;
	double x11;
	double x12;
	double x13;
	double x21;
	double x22;
	double x23;
	double result1;
	double result2;
	double result3;
	double discriminant;

	x1 = main.dir.dir.x * main.dir.dir.x;
	x2 = main.dir.dir.y * main.dir.dir.y;
	x3 = main.dir.dir.z * main.dir.dir.z;
	result1 = x1 + x2 + x3;
	x11 = ((main.cam.cam.x - main.sphere[i].pos.x) * main.dir.dir.x);
	x12 = ((main.cam.cam.y - main.sphere[i].pos.y) * main.dir.dir.y);
	x13 = ((main.cam.cam.z - main.sphere[i].pos.z) * main.dir.dir.z);
	result2 = 2 * (x11 + x12 + x13);
	x21 = ((main.cam.cam.x - main.sphere[i].pos.x) * (main.cam.cam.x - main.sphere[i].pos.x)) - (main.sphere[i].radius * main.sphere[i].radius);
	x22 = ((main.cam.cam.y - main.sphere[i].pos.y) * (main.cam.cam.y - main.sphere[i].pos.y)) - (main.sphere[i].radius * main.sphere[i].radius);
	x23 = ((main.cam.cam.z - main.sphere[i].pos.z) * (main.cam.cam.z - main.sphere[i].pos.z)) - (main.sphere[i].radius * main.sphere[i].radius);
	result3 = x21 + x22 + x23;
	discriminant = (result2 * result2) - (4 * result1 * result3);
	// printf("%f\n", discriminant);
	if (discriminant < 0)
	{
		main.t1 = 10000;
		main.t2 = 10000;
		return (main);
	}
	main.t1 = (-result2 + sqrt(discriminant)) / (2 * result1);
	main.t2 = (-result2 - sqrt(discriminant)) / (2 * result1);

	return (main);
}

int		sphere_color(t_main main, int t_min, int t_max)
{
	double closest_t = 10000;
	int closest_sphere = -1;
	int i = 0;
	while (i < 3)
	{
		main = intersect_ray(main, i);
		if (main.t1 > t_min && main.t1 < t_max && main.t1 < closest_t)
		{
			closest_t = main.t1;
			closest_sphere = i;
		}
		if (main.t2 > t_min && main.t2 < t_max && main.t2 < closest_t)
		{
			closest_t = main.t2;
			closest_sphere = i;
		}
		i++;
	}
	if (closest_sphere == -1)
		return (0);
	return (main.sphere[closest_sphere].color.r);
	
}

void	rtv(t_main main)
{
	main = create_sdl(main);
	main.viewport.view.x = 0.5;
	main.viewport.view.y = 0.5;
	main.viewport.view.z = 0.5;

	

	int x;
	int y = 0;
	int i = 0;
	main.sphere = malloc(sizeof(t_sphere) * 3);
	main.sphere[0].pos.x = -1;
	main.sphere[0].pos.y = 1;
	main.sphere[0].pos.z = 1;
	main.sphere[0].radius = 1;
	main.sphere[0].color.r = 40;
	main.sphere[0].color.g = 0;
	main.sphere[0].color.b = 0;

	main.sphere[1].pos.x = 0;
	main.sphere[1].pos.y = 1;
	main.sphere[1].pos.z = 1;
	main.sphere[1].radius = 1;
	main.sphere[1].color.r = 100;
	main.sphere[1].color.g = 0;
	main.sphere[1].color.b = 0;

	main.sphere[2].pos.x = 1;
	main.sphere[2].pos.y = 0;
	main.sphere[2].pos.z = 1;
	main.sphere[2].radius = 1;
	main.sphere[2].color.r = 255;
	main.sphere[2].color.g = 0;
	main.sphere[2].color.b = 0;
	while(!main.done)
	{
		if (i == 0)
		{
			while(y < WINH)
			{
				x = 0;
				while(x < WINW)
				{
					main = canvastoviewport(x - (WINW / 2), (WINH / 2) - y, main);
					// main = intersect_ray(main);
					SDL_SetRenderDrawColor(main.sdl.rend, sphere_color(main, 1, 10000), 0, 0, 255);
					SDL_RenderDrawPoint(main.sdl.rend, x, y);
					//отрисовка
					x++;
				}
				y++;
			}
			// SDL_RenderClear(main.sdl.rend);
			SDL_RenderPresent(main.sdl.rend);
			i++;
		}
		// SDL_RenderClear(main.sdl.rend);
			
		// SDL_RenderClear(main.sdl.rend);
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
