#include "maze.h"

SDL_Renderer *renderer;
SDL_Window *window;

void sdl_init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Experiment", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void process(void)
{
	SDL_Event event;
	const Uint8 *keyStates = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = false;
	}
	player_moves(keyStates);
}

void clear(void)
{
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderClear(renderer);
}

void Screen(void)
{
	SDL_RenderPresent(renderer);
}

void sdl_exit(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

