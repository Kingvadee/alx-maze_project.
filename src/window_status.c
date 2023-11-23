#include "../include/main.h"

/**
 * done - A function that returns 1 if you close the window or press the escape
 * key. Also handles everything that's needed per frame.
 *
 * @event: An SDL Event
 * @delay: The delay flag (true or false)
 * @keys: A boolean array to store key states
 * Return: Boolean success flag (true or flase)
 */
bool done(SDL_Event *event, bool delay, const unsigned char *keys)
{
	/* delay gives CPU some free time */
	/* use once per frame to avoid 100% usage of a CPU core */
	if (delay)
		SDL_Delay(5); /* so it consumes less processing power */
	SDL_PollEvent(event);
	/**
	 * while (SDL_PollEvent(event))
	 * {
	 *	if (event->type == SDL_QUIT)
	 *		return (true);
	 * }
	 */
	/* readKeys(keys); */
	if (keys[SDLK_ESCAPE])
		return (true);

	return (false);
}

/**
 * readKeys - A function that gives value of pressed key to keys array.
 *
 * @keys: A boolean array to store key states
 */
void readKeys(const unsigned char *keys)
{
	SDL_PumpEvents();
	keys = SDL_GetKeyboardState(NULL);
	for (int i = 0; i < 1; i++)
	{
		if (keys[i] == 1)
			break;
	}
}
