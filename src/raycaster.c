#include "../include/main.h"

/**
 * raycaster - A function to perform raycasting operations.
 *
 * @object: struct of type Vector containing all coordinates of that oject
 * @time: Time of current frame
 * @oldTime: Time of previous frame
 * @instance: struct of type SDL_Instance
 * @event: An SDL Event
 * @delay: The delay flag (true or false)
 * @keys: A boolean array to store key states
 * Return: 0 (Success)
 */
int raycaster(Vector object, double *time, double *oldTime,
			SDL_Instance *instance, SDL_Event *event, bool delay,
			const unsigned char *keys)
{
	while (!done(event, delay, keys))
		break;
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		/* x-coord in camera space */
		double cameraX = 2 * x / SCREEN_WIDTH - 1;
		/* Calculate ray direction vector */
		double rayDirX = object.dirX + object.planeX * cameraX;
		double rayDirY = object.dirY + object.planeY * cameraX;
		/* Calculate map position of ray origin */
		int mapX = floor(object.posX);
		int mapY = floor(object.posY);
		/* Calculate distance to next x and y grid lines */
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirY);
		/* Calculate initial step and side distances */
		double sideDistX, sideDistY, perpWallDist;
		int stepX, stepY, wall_height, wall_top, wall_bottom;
		int hit = 0;
		int side = 0; /* was a NS or a EW wall hit? */
		int worldMap[MAP_WIDTH][MAP_HEIGHT];
		/* World map */
		generate_map(worldMap);
		calculate_distances(object, rayDirX, rayDirY, &sideDistX,
			&sideDistY, &stepX, &stepY, mapX, mapY, deltaDistX, deltaDistY);
		int wall_code = DDA(&hit, &side, &sideDistX, &sideDistY, deltaDistX,
							deltaDistY, &mapX, &mapY, stepX, stepY, worldMap);

		calcuate_projection(side, sideDistX, sideDistY,	deltaDistX, deltaDistY,
						&perpWallDist, &wall_height, &wall_top, &wall_bottom);
		render_walls(instance->renderer, wall_top, wall_bottom, wall_code, side, x);
		/* drawMiniMap(worldMap, instance, object); */
	}
	fps_count(time, oldTime);

	return (0);
}

/**
 * calculate_distances - A function to calculate all important coordinates at
 * a given point in time.
 *
 * @object: struct of type Vector containing all coordinates of that oject
 * @rayDirX: Ray position and direction in x-axis
 * @rayDirY: Ray position and direction in y-axis
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 */
void calculate_distances(Vector object, double rayDirX, double rayDirY,
						double *sideDistX, double *sideDistY, int *stepX,
						int *stepY, int mapX, int mapY, double deltaDistX,
						double deltaDistY)
{
	*stepX = 0;
	*stepY = 0;
	/* calculate step and initial sideDist */
	if (rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (object.posX - mapX) * deltaDistX;
	} else
	{
		*stepX = 1;
		*sideDistX = (mapX + 1.0 - object.posX) * deltaDistX;
	}

	if (rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (object.posY - mapY) * deltaDistY;
	} else
	{
		*stepY = 1;
		*sideDistY = (mapY + 1.0 - object.posY) * deltaDistY;
	}
}

/**
 * DDA - Digital Differential Analysis
 *
 * @hit: Integer value (1 if wall was hit else 0)
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @worldMap: A 2-dimensional array of integer values
 * Return: Code of the wall if wall was hit else 0
 */
int DDA(int *hit, int *side, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX,
		int stepY, int (*worldMap)[MAP_WIDTH])
{
	/* perform DDA */
	while (*hit == 0)
	{
		/* Move to next grid cell */
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*hit = worldMap[*mapX][*mapY];
			*side = 0;
		} else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*hit = worldMap[*mapX][*mapY];
			*side = 1;
		}
	}

	return (*hit);
}

/**
 * calculate_projection - A function that calculates the values necessary for
 * camera projection.
 *
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @perpWallDist: Perpendicular distance from ray to wall
 * @wall_height: Height of the wall
 * @wall_top: Top of the wall
 * @wall_bottom: Bottom of the wall
 * Return: struct of type Projection
 */
Projection calcuate_projection(int side, double sideDistX, double sideDistY,
						double deltaDistX, double deltaDistY,
						double *perpWallDist, int *wall_height, int *wall_top,
						int *wall_bottom)
{
	Projection pixel_coordinates;

	/*
	* Calculate distance projected on camera direction
	* (Euclidean distance would give fisheye effect!)
	*/
	if (side == 0)
		*perpWallDist = (sideDistX - deltaDistX);
	else
		*perpWallDist = (sideDistY - deltaDistY);

	/* Calculate height of line to draw on screen */
	int lineHeight = (int)(SCREEN_HEIGHT / *perpWallDist);

	/* calculate lowest and highest pixel to fill in current stripe */
	int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;

	pixel_coordinates.drawStart = drawStart;
	pixel_coordinates.drawEnd = drawEnd;

	/* Calculate wall height on screen */
	*wall_height = (int)(SCREEN_HEIGHT / *perpWallDist);

	/* Calculate top and bottom pixels of wall on screen */
	*wall_top = SCREEN_HEIGHT / 2 - *wall_height / 2;
	*wall_bottom = *wall_top + *wall_height;

	if (*wall_top < 0 && *wall_bottom)
		*wall_top = 0;

	return (pixel_coordinates);
}
