maptool : maptool.c ../engine/core.c ../engine/tile.c ./cmd_parser.c
	gcc -g -o ../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

game : game.c ../engine/core.c ../engine/tile.c ./cmd_parser.c
	gcc -g -o ../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf