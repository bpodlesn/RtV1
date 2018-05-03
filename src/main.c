/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:20:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/03 12:53:10 by bpodlesn         ###   ########.fr       */
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

void	rtv(t_main main)
{
	main.sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	while(!main.done)
	{
		SDL_RenderPresent(main.sdl.rend);
		SDL_RenderClear(main.sdl.rend);
		main = key(main);
	}
}

int	main(int argc, char **argv)
{
	t_main	main;

	main.done = 0;
	if (argc == 1)
		rtv(main);
	else
		exit (0);
	ft_strlen(argv[1]);
	return (0);
}