/*
   File: main.c
   Author: [Ojeifo David]
   Description: Simple maze rendering using SDL and raycasting.
*/
// Include the "maze.h" header file, because it contains necessary declarations
#include "maze.h"

// Define constants for screen dimensions, map size, box size, and initial player position
int width = 1500;     // Width of the screen
int width2d = 820;    // 2D width (used in raycasting)
int height = 820;     // Height of the screen
int mapW = 15;        // Width of the map
int mapH = 15;        // Height of the map
int boxSize = 32;     // Size of each box in the maze
bool running;         // Flag to control the game loop

// Define the initial player position, angle, and direction
Vector pPos = {70, 70};  // Player position
float pA = PI / 2;        // Player angle (initially facing upwards)
Vector pd = {0, 0};       // Player direction

// Main function
int main(int argc, char **argv)
{
    // Initialize SDL and set up the game window
    sdl_init();

    // Set the running flag to true to start the game loop
    running = true;

    // Main game loop
    while (running)
    {
        // Process user input and update game state
        process();

        // Update player direction based on the player's angle
        pd.x = cos(pA);
        pd.y = sin(pA);

        // Clear the screen for the next frame
        clear();

        // Draw the maze
        drawMap();

        // Draw the player at the current position
        player_drawing();

        // Draw sections of the environment based on raycasting
        sections_drawing();

        // Update the screen to show the latest frame
        Screen();
    }

    // Clean up SDL resources and exit the program
    sdl_exit();
    return 0;
}
