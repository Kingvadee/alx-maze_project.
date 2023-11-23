#include "../include/main.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	SDL_Instance instance;
	SDL_Event event = {0};
	const unsigned char keys[KEYS];
	Vector player;
	double time = 0; /* time of current frame */
	double oldTime = 0; /* time of previous frame */
	_Bool quit = false; /* the quit flag */

	player.dirX = -1;
	player.dirY = 0;
	player.posX = 22;
	player.posY = 12;
	player.planeX = 0;
	player.planeY = 0.66;

	/* Start up SDL and create window */
	if (!initialize_SDL(&instance))
	{
		fprintf(stderr, "Failed to initialize!\n");
	} else
	{
		while (!quit)
		{
			SDL_SetRenderDrawColor(instance.renderer, 0x0, 0x0, 0x0, 0x0);
			SDL_RenderClear(instance.renderer);
			if (poll_events() == 1)
				break;
			raycaster(player, &time, &oldTime, &instance, &event, true,
					keys);
			SDL_RenderPresent(instance.renderer);
			/* Hack to get window to stay up */
			keep_window(&quit);
		}
		end(&instance);
	}
	return (0);
}
