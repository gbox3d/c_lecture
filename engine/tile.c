
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,
             Uint16 _x, Uint16 _y, Uint16 _index,
             Uint16 tile_size,
             Uint16 tile_set_width,
             Uint16 zoom)
{
  SDL_Rect _tmpDstRt;
  _tmpDstRt.x = _x * (tile_size * zoom);
  _tmpDstRt.y = _y * (tile_size * zoom);
  _tmpDstRt.w = (tile_size * zoom);
  _tmpDstRt.h = (tile_size * zoom);

  SDL_Rect _tmpSrcRt;
  _tmpSrcRt.x = (_index % tile_set_width) * tile_size;
  _tmpSrcRt.y = (_index / tile_set_width) * tile_size;
  _tmpSrcRt.w = tile_size;
  _tmpSrcRt.h = tile_size;

  SDL_RenderCopy(pRenderer, pTex, &_tmpSrcRt, &_tmpDstRt);
}

void putMap(Uint16 x, Uint16 y, Sint16 nTile, Sint16 *map, Uint16 map_size)
{
  // int _x = (_event.motion.x) / 32;
  // int _y = (_event.motion.y) / 32;

  if (x < map_size && y < map_size)
  {
    int _tileIndex = y * map_size + x;
    map[_tileIndex] = nTile;
  }
}

void drawWorld(SDL_Renderer *pRender, SDL_Texture *pTileSet, int tile_size,
               int tileset_width,
               int zoom,
               int x, int y, int map_size, Sint16 *map)
{
  for (int i = 0; i < 64; i++)
  {
    Sint16 _index = map[i];
    if (_index != -1)
    {
      putTile(pRender, pTileSet, i % map_size, i / map_size,
              _index, tile_size, tileset_width, zoom);
    }
  }
}

SDL_bool loadMap(const char *filename, Sint16 *map[2])
{
  SDL_RWops *rw = SDL_RWFromFile(filename, "rb");
  if (!rw)
    return SDL_FALSE;
  SDL_RWread(rw, map[0], sizeof(Uint16), 64);
  SDL_RWread(rw, map[1], sizeof(Uint16), 64);
  SDL_RWclose(rw);

  return SDL_TRUE;
}

SDL_bool saveMap(const char *filename, Sint16 *map[2])
{
  SDL_RWops *rw = SDL_RWFromFile(filename, "wb");
  if (!rw)
    return SDL_FALSE;
  SDL_RWwrite(rw, map[0], sizeof(Uint16), 64);
  SDL_RWwrite(rw, map[1], sizeof(Uint16), 64);
  SDL_RWclose(rw);

  return SDL_TRUE;
}