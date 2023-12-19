#include "maze.h"

int map[225] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1,
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

Vector mapStart = {10, 130};

void drawMap(void)
{
	int currX = mapStart.x, currY = mapStart.y, row = 0;
	for (int i = 0; i < mapW * mapH; i++)
	{
		if ((int)i / mapW != row)
			currY += boxSize;
		currX = mapStart.x;
		row++;
		if (map[i] == 1)
		{
			SDL_SetRenderDrawColor(renderer, 140, 140, 140, 255);
			SDL_Rect rect = {currX, currY, boxSize - 1, boxSize - 1};
			SDL_RenderFillRect(renderer, &rect);
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
			SDL_Rect rect = {currX, currY, boxSize - 1, boxSize - 1};
			SDL_RenderFillRect(renderer, &rect);
		}
		currX += boxSize;
	}
}
void player_drawing(void)
{
	SDL_SetRenderDrawColor(renderer, 100, 100, 250, 255);
	SDL_Rect rect = {pPos.x + mapStart.x, pPos.y + mapStart.y, 10, 10};
	SDL_RenderFillRect(renderer, &rect);
}
void sections_drawing(void)
{
	float distance;
	double distancefix;
	float rA = pA - 0.6;
	Vector rd;
	int rectwidth = 0;
	while (rA < pA + 0.6)
	{
		rd.x = cos(rA);
		rd.y = sin(rA);
		distance = casting(rd);
		float diffA = pA - rA;
		if (diffA < 0)
			diffA += PI * 2;
		else if (diffA >= PI * 2)
			diffA -= PI * 2;
		distancefix = distance * cos(diffA);
		int lineheight = boxSize * width2d / distancefix;
		int offY = (height - lineheight) / 2;
		SDL_Rect top = {rectwidth, 0, 6, (height - lineheight) / 2};
		SDL_Rect wall = {rectwidth, offY, 6, lineheight};
		SDL_Rect bottom = {rectwidth, offY + lineheight, 5, height};
		SDL_RenderFillRect(renderer, &wall);
		SDL_SetRenderDrawColor(renderer, 24, 82, 200, 255);
		SDL_RenderFillRect(renderer, &top);
		SDL_SetRenderDrawColor(renderer, 56, 97, 13, 255);
		SDL_RenderFillRect(renderer, &bottom);
		Vector pt = {distance * rd.x + pPos.x + mapStart.x, distance * rd.y + pPos.y + mapStart.y};
		rectwidth += 5;
		rA += 0.005;
	}
}

