#include "maze.h"

// Global variables for SDL rendering
SDL_Renderer *renderer;
SDL_Window *window;

// Initialize SDL window and renderer
void sdl_init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("SDL Experiment", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

// Process SDL events and handle quitting
void process(void)
{
    SDL_Event event;
    const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
    }

    // Process player movements based on keyboard input
    player_moves(keyStates);
}

// Clear the SDL renderer with a specified color
void clear(void)
{
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
    SDL_RenderClear(renderer);
}

// Present the rendered content to the screen
void Screen(void)
{
    SDL_RenderPresent(renderer);
}

// Clean up and exit SDL
void sdl_exit(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
