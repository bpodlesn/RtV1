/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:48:28 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 15:49:02 by bpodlesn         ###   ########.fr       */
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
	if (keykey[SDL_SCANCODE_UP] && main.go-- > 0)
		main.cam.cam.y += 0.1;
	if (keykey[SDL_SCANCODE_DOWN] && main.go-- > 0)
		main.cam.cam.y -= 0.1;
	if (keykey[SDL_SCANCODE_LEFT] && main.go-- > 0)
		main.cam.cam.x -= 0.1;
	if (keykey[SDL_SCANCODE_RIGHT] && main.go-- > 0)
		main.cam.cam.x += 0.1;
	if (keykey[SDL_SCANCODE_W] && main.go-- > 0)
		main.cam.cam.z += 0.1;
	if (keykey[SDL_SCANCODE_S] && main.go-- > 0)
		main.cam.cam.z -= 0.1;
	return (main);
}
