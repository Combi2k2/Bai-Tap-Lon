#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define X   first
#define Y   second

typedef pair<int,int>   Poi;

const int   BOARD_WIDTH     = 10;
const int   BOARD_HEIGHT    = 20;

int Filled[BOARD_HEIGHT][BOARD_WIDTH];

vector<int> new_X(4);
vector<int> new_Y(4);

bool check()    {
    for(int i = 0 ; i < 4 ; ++i)    {
        if (new_X[i] < 0)   return  false;
        if (new_X[i] >= BOARD_WIDTH)    return  false;
        if (new_Y[i] >= BOARD_HEIGHT)   return  false;
        if (new_Y[i] < 0)   continue;

        if (Filled[new_Y[i]][new_X[i]])
            return  false;
    }
    current_posX = new_X;
    current_posY = new_Y;

    return  true;
}
int deltaX = 0;
int Rotate = 0;

void push() {
    for(int i = 0 ; i < 4 ; ++i)
        new_X[i] = current_posX[i] + deltaX,
        new_Y[i] = current_posY[i];

    deltaX = 0;
    check();
}
void roll() {
    if (Rotate == 0 || index == 7)  {
        new_X = current_posX;
        new_Y = current_posY;
        return;
    }

    for(int i = 0 ; i < 4 ; ++i)    {
        int dx = current_posX[i] - current_posX[1];
        int dy = current_posY[i] - current_posY[1];

        int nX = current_posX[1];
        int nY = current_posY[1];

        if (Rotate > 0)    nX += dy, nY -= dx;
        if (Rotate < 0)    nX -= dy, nY += dx;

        new_X[i] = nX;
        new_Y[i] = nY;
    }
    Rotate = 0;

    vector<int> vec = {0,1,-1,2,-2};

    for(int offset : vec)   {
        for(int&x : new_X)  x += offset;    if (check())    return;
        for(int&x : new_X)  x -= offset;
    }
}
void Hold() {
    if (Held < 0)   {
        Held = index;
        spawnTile();
    }
    else    {
        current_posX.clear();
        current_posY.clear();

        for(int i = 0 ; i < 4 ; ++i)    {
            current_posX.push_back(Pos[Held][i] % 2 + 4);
            current_posY.push_back(Pos[Held][i] / 2 - 3);
        }

        swap(Held,index);
    }
}
