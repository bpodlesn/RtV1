/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:19:58 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/05/29 17:02:51 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	update_screen(t_main main)
{
	int x;
	int y;
	int j;

	y = -1;
	j = 0;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			main = canvastoviewport(x - (WINW / 2), (WINH / 2) - y, main);
			main.screencolor[j] = what_color(main);
			j++;
		}
	}
	SDL_UpdateTexture(main.sdl.fillscreen, NULL, main.screencolor, WINW * 4);
	SDL_SetRenderDrawColor(main.sdl.rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(main.sdl.rend, main.sdl.fillscreen, NULL,
	NULL);
	SDL_RenderPresent(main.sdl.rend);
	SDL_RenderClear(main.sdl.rend);
}
