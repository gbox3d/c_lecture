#ifndef __TILE_H
#define __TILE_H
// void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,Uint16 _x,Uint16 _y, Uint16 _index);
void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,
Uint16 _x,Uint16 _y, Uint16 _index,
Uint16 tile_size,
Uint16 tile_set_width,
Uint16 zoom
);
void putMap(Uint16 x,Uint16 y,Sint16 nTile,Sint16 *map,Uint16 map_size);

SDL_bool loadMap(const char *filename, Sint16 *map[2]);
SDL_bool saveMap(const char *filename, Sint16 *map[2]);

void drawWorld(SDL_Renderer *pRender, SDL_Texture *pTileSet, int tile_size,
               int tileset_width,
               int zoom,
               int x, int y, int map_size, Sint16 *map);

#endif