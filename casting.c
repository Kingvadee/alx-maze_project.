#include "maze.h"


// Function to check if a given point is on a wall in the maze
bool wall_pun(Vector pt)
{
    // Snap the point to the nearest grid position
	Vector p;
	p.x = ((int)pt.x / boxSize) * boxSize;
	p.y = ((int)pt.y / boxSize) * boxSize;

    // Calculate the index of the point in the map array
	int i = p.y / boxSize * mapW + p.x / boxSize;

    // Check if the point is on a wall (map value of 1)
	if (map[i] == 1)
		return true;
	return false;
}

// Function to perform ray casting in the maze
float casting(Vector rd)
{
    Vector unitlength, raylength, dir, lasttile;
	float distance;
	bool hit;
	int index_map;
	char wall;

    // Calculate the unit lengths in x and y directions for the ray
	unitlength.x = sqrt(1 + (rd.y / rd.x) * (rd.y / rd.x));
	unitlength.y = sqrt(1 + (rd.x / rd.y) * (rd.x / rd.y));

    // Snap the player's position to the nearest grid position
	lasttile.x = ((int)pPos.x / boxSize) * boxSize;
	lasttile.y = ((int)pPos.y / boxSize) * boxSize;

    // Determine the direction of the ray and initialize ray lengths
	if (rd.x < 0)
	{
		dir.x = -1;
		raylength.x = (pPos.x - lasttile.x) * unitlength.x;
	}
	else
	{
		dir.x = 1;
		raylength.x = (lasttile.x + boxSize - pPos.x) * unitlength.x;
	}
	if (rd.y < 0)
	{
		dir.y = -1;
		raylength.y = (pPos.y - lasttile.y) * unitlength.y;
	}
	else
	{
		dir.y = 1;
		raylength.y = (lasttile.y + boxSize - pPos.y) * unitlength.y;
	}

    // Initialize distance and hit variables
	distance = 0;
	hit = false;
	index_map = 0;

    // Loop until a wall is hit or the maximum distance is reached
	for (; !hit && distance < 750;)
	{
        // Check if the next horizontal or vertical wall is closer
		if (raylength.x < raylength.y)
		{
            // Move to the next horizontal wall
			lasttile.x += dir.x * boxSize;
			distance = raylength.x;
			raylength.x += unitlength.x * boxSize;
			wall = 'h';
		}
		else
		{
            // Move to the next vertical wall
			lasttile.y += dir.y * boxSize;
			distance = raylength.y;
			raylength.y += unitlength.y * boxSize;
			wall = 'v';
		}

        // Check if the new position is within the maze boundaries and if it's on a wall
		if (lasttile.x >= 0 && lasttile.x < width2d && lasttile.y >= 0 && lasttile.y < height)
		{
			if (wall_pun(lasttile))
				hit = true;
		}
	}

    // Set the render draw color based on the type of wall hit
	if (wall == 'h')
		SDL_SetRenderDrawColor(renderer, 71, 5, 154, 255);
	else
		SDL_SetRenderDrawColor(renderer, 100, 16, 0, 203);

    // Return the distance to the hit wall
	return distance;
}
