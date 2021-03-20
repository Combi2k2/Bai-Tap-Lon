#include <bits/stdc++.h>

using namespace std;

vector<int> simulateX(4);
vector<int> simulateY(4);

int To_The_Filled_Zone;

void drawVirtualResult()    {
    To_The_Filled_Zone = 20;

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = current_posX[i];
        int h = current_posY[i];

        if (h < 0)  h = 0;

        for(; h < BOARD_HEIGHT - 1 ; ++h)
            if (Filled[h + 1][x])
                break;

        if (To_The_Filled_Zone > h - current_posY[i])
            To_The_Filled_Zone = h - current_posY[i];
    }
    for(int i = 0 ; i < 4 ; ++i)    {
        int x = simulateX[i] = current_posX[i];
        int y = simulateY[i] = current_posY[i] + To_The_Filled_Zone;

        if (y < 0)  continue;

//        bool covered = false;

//        for(int j = 0 ; j < 4 ; ++j)    {
//            if (x != current_posX[j])   continue;
//            if (y != current_posY[i])   continue;
//
//            covered = true;
//        }
//        if (covered)    continue;

        SDL_Rect rectangle;

        SDL_SetRenderDrawColor(renderer, color[index][0], color[index][1], color[index][2], 255);

        rectangle.x = 50 + x * 30;
        rectangle.y = 50 + y * 30;
        rectangle.h = rectangle.w = 29;

        SDL_RenderFillRect(renderer, &rectangle);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        rectangle.x++;
        rectangle.y++;
        rectangle.h = rectangle.w = 27;

        SDL_RenderFillRect(renderer, &rectangle);
    }
}
