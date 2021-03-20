#include <bits/stdc++.h>

using namespace std;

const vector<int> CYAN    = {0, 255, 255};
const vector<int> BLUE    = {0, 0, 255};
const vector<int> ORANGE  = {255, 165, 0};
const vector<int> YELLOW  = {255, 255, 0};
const vector<int> LIME    = {0, 255, 0};
const vector<int> PURPLE  = {128, 0, 128};
const vector<int> RED     = {255, 0, 0};
const vector<int> WHITE   = {255, 255, 255};
const vector<int> BLACK   = {0, 0, 0};
const vector<int> GREEN   = {0, 128, 0};

SDL_Rect rectangle;

vector<int> Pos[] = {{},
                     {1,3,5,7},     //I
                     {2,4,5,7},     //Z
                     {3,5,4,6},     //S
                     {3,5,4,7},     //T
                     {2,5,3,7},     //L
                     {3,5,7,6},     //J
                     {2,3,4,5}};    //O
vector<int> color[] = {BLACK,
                       CYAN,
                       GREEN,
                       RED,
                       PURPLE,
                       BLUE,
                       ORANGE,
                       YELLOW};

void drawSquare(int x,int y,vector<int> col)    {
    SDL_Rect rectangle;
    SDL_SetRenderDrawColor(renderer, col[0], col[1], col[2], 255);

    rectangle.x = x;
    rectangle.y = y;
    rectangle.h = rectangle.w = 29;

    SDL_RenderFillRect(renderer, &rectangle);

    if (col == BLACK)   return;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    rectangle.x += 3;
    rectangle.y += 3;
    rectangle.h = rectangle.w = 23;

    SDL_RenderFillRect(renderer, &rectangle);

    SDL_SetRenderDrawColor(renderer, col[0], col[1], col[2], 255);

    rectangle.x += 3;
    rectangle.y += 3;
    rectangle.h = rectangle.w = 17;

    SDL_RenderFillRect(renderer, &rectangle);
}
void draw(int x,int y,vector<int> col)  {
    if (y < 0)  return;

    x = x * 30 + 50;
    y = y * 30 + 50;

    drawSquare(x,y,col);
}

vector<int> current_posX;
vector<int> current_posY;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int index;

int Tile_queue[3];
int Size = 0;

int Held = -1;

void spawnTile()    {
    while (Size < 3)    {
        int idx = rng() % 7 + 1;
        if (idx < 1)
            idx += 7;

        Tile_queue[Size++] = idx;
    }
    index = Tile_queue[0];

    Tile_queue[0] = Tile_queue[1];
    Tile_queue[1] = Tile_queue[2];  Size = 2;

    current_posX.clear();
    current_posY.clear();

    for(int i = 0 ; i < 4 ; ++i)    {
        current_posX.push_back(Pos[index][i] % 2 + 4);
        current_posY.push_back(Pos[index][i] / 2 - 3);
    }
}
