#include "maze.h"

void player_moves(const Uint8 *keyStates)
{
	Vector p_next = pPos;
	if (keyStates[SDL_SCANCODE_W])
	{
		if (pd.y < 0)
			p_next.y -= 10;
		else
			p_next.y += 10;
		if (!wall_pun(p_next))
			pPos.y += pd.y * 1.2;
		p_next = pPos;
		if (pd.x < 0)
			p_next.x -= 10;
		else
			p_next.x += 10;
		if (!wall_pun(p_next))
			pPos.x += pd.x * 1.2;
	}
	if (keyStates[SDL_SCANCODE_S])
	{
		if (pd.y < 0)
			p_next.y += 10;
		else
			p_next.y -= 10;
		if (!wall_pun(p_next))
			pPos.y -= pd.y * 1.2;
		p_next = pPos;
		if (pd.x < 0)
			p_next.x += 10;
		else
			p_next.x -= 10;
		if (!wall_pun(p_next))
			pPos.x -= pd.x * 1.2;
	}
	if (keyStates[SDL_SCANCODE_A])
	{
		pA -= 0.03;
		if (pA <= PI * 2)
			pA += PI * 2;
	}
	if (keyStates[SDL_SCANCODE_D])
	{
		pA += 0.03;
		if (pA > PI * 2)
			pA -= PI * 2;
	}
}

