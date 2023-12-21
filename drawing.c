#include "maze.h"


// Define the maze map with 1s as walls and 0s as open spaces
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

// Starting position on the map
Vector mapStart = {10, 130};

// Function to draw the maze
void drawMap(void)
{
    // Initialize current X and Y coordinates, and row counter
    int currX = mapStart.x, currY = mapStart.y, row = 0;

    // Iterate through the map and draw each cell
    for (int i = 0; i < mapW * mapH; i++)
    {
        // Check if a new row is started
        if ((int)i / mapW != row)
            currY += boxSize;

        // Reset current X coordinate and increment row
        currX = mapStart.x;
        row++;

        // Set render color based on map value (1 for wall, 0 for open space)
        if (map[i] == 1)
        {
            SDL_SetRenderDrawColor(renderer, 140, 140, 140, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        }

        // Draw a rectangle representing the cell
        SDL_Rect rect = {currX, currY, boxSize - 1, boxSize - 1};
        SDL_RenderFillRect(renderer, &rect);

        // Move to the next column
        currX += boxSize;
    }
}

// Function to draw the player's position
void player_drawing(void)
{
    // Set render color for the player
    SDL_SetRenderDrawColor(renderer, 100, 100, 250, 255);

    // Draw a rectangle representing the player at their position
    SDL_Rect rect = {pPos.x + mapStart.x, pPos.y + mapStart.y, 10, 10};
    SDL_RenderFillRect(renderer, &rect);
}

// Function to draw sections of the environment based on raycasting
void sections_drawing(void)
{
    // Variables for distance, angle, ray direction, and rectangle width
    float distance;
    double distancefix;
    float rA = pA - 0.6;
    Vector rd;
    int rectwidth = 0;

    // Iterate through a range of angles for raycasting
    while (rA < pA + 0.6)
    {
        // Calculate ray direction
        rd.x = cos(rA);
        rd.y = sin(rA);

        // Perform raycasting and calculate corrected distance
        distance = casting(rd);
        float diffA = pA - rA;
        if (diffA < 0)
            diffA += PI * 2;
        else if (diffA >= PI * 2)
            diffA -= PI * 2;
        distancefix = distance * cos(diffA);

        // Calculate line height and offset
        int lineheight = boxSize * width2d / distancefix;
        int offY = (height - lineheight) / 2;

        // Define rectangles for the top, wall, and bottom sections
        SDL_Rect top = {rectwidth, 0, 6, (height - lineheight) / 2};
        SDL_Rect wall = {rectwidth, offY, 6, lineheight};
        SDL_Rect bottom = {rectwidth, offY + lineheight, 5, height};

        // Render rectangles for the sections
        SDL_RenderFillRect(renderer, &wall);
        SDL_SetRenderDrawColor(renderer, 24, 82, 200, 255);
        SDL_RenderFillRect(renderer, &top);
        SDL_SetRenderDrawColor(renderer, 56, 97, 13, 255);
        SDL_RenderFillRect(renderer, &bottom);

        // Calculate the position of the intersection point
        Vector pt = {distance * rd.x + pPos.x + mapStart.x, distance * rd.y + pPos.y + mapStart.y};

        // Increment rectangle width and angle for the next iteration
        rectwidth += 5;
        rA += 0.005;
    }
}
