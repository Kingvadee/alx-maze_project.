#include "maze.h"

bool wall_pun(Vector pt)
{
	Vector p;
	p.x = ((int)pt.x / boxSize) * boxSize;
	p.y = ((int)pt.y / boxSize) * boxSize;
	int i = p.y / boxSize * mapW + p.x / boxSize;
	if (map[i] == 1)
		return true;
	return false;
}

float casting(Vector rd)
{
	Vector unitlength, raylength, dir, lasttile;
	float distance;
	bool hit;
	int index_map;
	unitlength.x = sqrt(1 + (rd.y / rd.x) * (rd.y / rd.x));
	unitlength.y = sqrt(1 + (rd.x / rd.y) * (rd.x / rd.y));
	lasttile.x = ((int)pPos.x / boxSize) * boxSize;
	lasttile.y = ((int)pPos.y / boxSize) * boxSize;
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
	distance = 0;
	hit = false;
	index_map = 0;
	char wall;
	for (; !hit && distance < 750;)
	{
		if (raylength.x < raylength.y)
		{
			lasttile.x += dir.x * boxSize;
			distance = raylength.x;
			raylength.x += unitlength.x * boxSize;
			wall = 'h';
		}
		else
		{
			lasttile.y += dir.y * boxSize;
			distance = raylength.y;
			raylength.y += unitlength.y * boxSize;
			wall = 'v';
		}
		if (lasttile.x >= 0 && lasttile.x < width2d && lasttile.y >= 0 && lasttile.y < height)
		{
			if (wall_pun(lasttile))
				hit = true;
		}
	}
	if (wall == 'h')
		SDL_SetRenderDrawColor(renderer, 71, 5, 154, 255);
	else
		SDL_SetRenderDrawColor(renderer, 100, 16, 0, 203);
	return distance;
}

