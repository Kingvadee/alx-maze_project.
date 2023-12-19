#include "maze.h"

int width = 1500;
int width2d = 820;
int height = 820;
int mapW = 15;
int mapH = 15;
int boxSize = 32;
bool running;

Vector pPos = {70, 70};
float pA = PI / 2;
Vector pd = {0, 0};
int main(int argc, char **argv)
{
	sdl_init();
	running = true;
	while (running)
	{
		process();
		pd.x = cos(pA);
		pd.y = sin(pA);
		clear();
		drawMap();
		player_drawing();
		sections_drawing();
		Screen();
	}
	sdl_exit();
	return (0);
}
