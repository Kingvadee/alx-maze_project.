#include "../include/main.h"

/**
 * verLine - A function to draw fast vertical line from (x,y1) to (x,y2),
 * with RGB color
 *
 * @x: Column iterator
 * @y1: The coordinate of the first vertical column to be drawn
 * @y2: The coordinate of the last vertical column to be drawn
 * @color: struct containing the RGBA values of a given color
 * @instance: struct of type SDL_Instance
 * Return: 0 else 1 (Success)
 */
int verLine(int x, int y1, int y2, ColorRGBA *color, SDL_Instance *instance)
{
	SDL_Surface *scr = instance->screenSurface;

	if (y2 < y1)
	{
		/* swap y1 and y2 */
		y1 += y2;
		y2 = y1 - y2;
		y1 -= y2;
	}
	if (y2 < 0 || y1 >= SCREEN_HEIGHT  || x < 0 || x >= SCREEN_WIDTH)
		return (0); /* no single point of the line is on screen */
	if (y1 < 0)
		y1 = 0; /* clip */
	if (y2 >= SCREEN_WIDTH)
		y2 = SCREEN_HEIGHT - 1; /* clip */

	Uint32 colorSDL = SDL_MapRGBA(scr->format, color->red, color->green,
								color->blue, (Uint8) (255 * color->alpha));
	Uint32 *bufp;

	bufp = (Uint32 *)scr->pixels + y1 * scr->pitch / 4 + x;
	unsigned int add = scr->pitch / 4;

	for (int y = y1; y <= y2; y++)
	{
		*bufp = colorSDL;
		bufp += add;
	}
	return (1);
}

/**
 * fps_count - A function to calculate the frame rate and return its value
 *
 * @time: Time of curent frame in seconds
 * @oldTime: Time of previous frame in seconds
 * Return: Value of frame rate (FPS)
 */
int fps_count(double *time, double *oldTime)
{
	/* timing for input and FPS counter */
	*oldTime = *time;
	*time = getTicks();

	/* frameTime is the time this frame has taken, in seconds */
	double frameTime = (*time - *oldTime) / 1000.0;

	fprintf(stderr, "Frame rate: %lf FPS\n", 1.0 / frameTime); /* FPS counter */

	/* speed modifiers */
	/*double moveSpeed = frameTime * 5.0;*//*constant value in squares/second*/
	/* double rotSpeed = frameTime * 3.0; */ /* the constant value in rads/s */

	return (frameTime);
}

/**
 * cls - A function to clear the screen and set its color to black
 *
 * @scr: SDL Screen Surface contained by the window
 */
void cls(SDL_Surface *scr)
{
	ColorRGBA color = rgba_color_code("black");
	Uint32 color_value = SDL_MapRGBA(scr->format, color.red, color.green,
									color.blue, (Uint8) (255 * color.alpha));

	SDL_FillRect(scr, NULL, color_value);
}

/**
 * render_walls - A function to render the walls on the screen.
 *
 * @renderer: The renderer of the window
 * @wall_top: The coordinate of the first vertical column to be drawn
 * @wall_bottom: The coordinate of the last vertical column to be drawn
 * @wall_code: The code of the wall to be drawn
 * @side: The side of the wall to be drawn
 * @x: The column iterator
 */
void render_walls(SDL_Renderer *renderer, int wall_top, int wall_bottom,
				int wall_code, int side, int x)
{
	/* Render wall strip on screen */
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		if (y < wall_top)
			continue;
		if (y >= wall_bottom)
			break;

		ColorRGBA color = color_wall(wall_code, side);

		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue,
								(Uint8) (255 * color.alpha));
		SDL_RenderDrawPoint(renderer, x, y);
	}
}
