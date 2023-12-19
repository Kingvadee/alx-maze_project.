#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.142

typedef struct vector
{
	float x;
	float y;
} Vector;

extern int map[];
extern bool running;
extern int width;
extern int height;
extern int mapW;
extern int mapH;
extern int width2d;
extern int boxSize;
extern float pA;
extern Vector pPos;
extern Vector pd;
extern Vector mapStart;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

void drawMap(void);
void player_drawing(void);
void sections_drawing(void);
void player_moves(const Uint8 *keyStates);
bool wall_pun(Vector pt);
float casting(Vector rd);
void sdl_init(void);
void process(void);
void clear(void);
void Screen(void);
void sdl_exit(void);

#endif

