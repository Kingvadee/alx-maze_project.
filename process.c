/*
 * File: player_movement.c
 * Description: Implements player movement based on keyboard input.
 */

#include "maze.h"

/**
 * Moves the player based on the keyboard input.
 *
 * @param keyStates The state of the keyboard keys.
 */
void player_moves(const Uint8 *keyStates)
{
    // Store the next potential position of the player
    Vector p_next = pPos;

    // Move forward (W key)
    if (keyStates[SDL_SCANCODE_W])
    {
        // Adjust the next position based on the player's direction
        if (pd.y < 0)
            p_next.y -= 10;
        else
            p_next.y += 10;

        // Check for collision with walls before updating the position
        if (!wall_pun(p_next))
            pPos.y += pd.y * 1.2;

        // Reset p_next for the next axis
        p_next = pPos;

        // Adjust the next position based on the player's direction
        if (pd.x < 0)
            p_next.x -= 10;
        else
            p_next.x += 10;

        // Check for collision with walls before updating the position
        if (!wall_pun(p_next))
            pPos.x += pd.x * 1.2;
    }

    // Move backward (S key)
    if (keyStates[SDL_SCANCODE_S])
    {
        // Adjust the next position based on the player's direction
        if (pd.y < 0)
            p_next.y += 10;
        else
            p_next.y -= 10;

        // Check for collision with walls before updating the position
        if (!wall_pun(p_next))
            pPos.y -= pd.y * 1.2;

        // Reset p_next for the next axis
        p_next = pPos;

        // Adjust the next position based on the player's direction
        if (pd.x < 0)
            p_next.x += 10;
        else
            p_next.x -= 10;

        // Check for collision with walls before updating the position
        if (!wall_pun(p_next))
            pPos.x -= pd.x * 1.2;
    }

    // Rotate left (A key)
    if (keyStates[SDL_SCANCODE_A])
    {
        pA -= 0.03;
        if (pA <= PI * 2)
            pA += PI * 2;
    }

    // Rotate right (D key)
    if (keyStates[SDL_SCANCODE_D])
    {
        pA += 0.03;
        if (pA > PI * 2)
            pA -= PI * 2;
    }
}
