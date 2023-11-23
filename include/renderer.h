#ifndef _RENDERING_H_
#define _RENDERING_H_

/* Divider for making the minimap smaller */
#define MINIMAP_DIVIDER 16
/* Dividers for making the player in the minimap smaller */
#define MINIMAP_PLAYER_WIDTH 4
#define MINIMAP_PLAYER_HEIGHT 4

void render_walls(SDL_Renderer *renderer, int wall_top, int wall_bottom,
				int wall_code, int side, int x);

#endif /* _RENDERING_H_ */
