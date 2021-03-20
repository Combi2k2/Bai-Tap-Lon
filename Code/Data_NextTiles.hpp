#include <bits/stdc++.h>

using namespace std;

void draw_NextTiles()   {
    //draw table containing next tiles

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect Zone;

    Zone = {405,45,219,189};    SDL_RenderFillRect(renderer, &Zone);    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    Zone = {410,50,209,179};    SDL_RenderFillRect(renderer, &Zone);

    for(int i = 0 ; i < 2 ; ++i)    {
        int id = Tile_queue[i];

        for(int j = 0 ; j < 4 ; ++j)    {
            int x = Pos[id][j] % 2 + 13 + i * 3;
            int y = Pos[id][j] / 2 + 1;

            drawSquare(x * 30 + 50,y * 30 + 50,color[id]);
        }
    }
    write("NEXT", 480, 50);
}
