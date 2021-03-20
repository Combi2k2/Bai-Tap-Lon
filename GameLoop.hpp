#include <bits/stdc++.h>

using namespace std;

int timer = 0;
int delay = DEFAULT_SPEED;
int time_elapsed;

SDL_Event e;

bool C_is_pressed = false;

bool Landing()  {
    for(int i = 0 ; i < 4 ; ++i)    {
        int x = new_X[i];
        int y = new_Y[i];

        if (y < 0)  return  false;

        Filled[y][x] = index;
    }
    C_is_pressed = false;
    spawnTile();

    return  true;
}
bool gameLoop() {
    timer += clock() - time_elapsed;
    time_elapsed = clock();

    if (SDL_PollEvent(&e))  {
        if (e.type == SDL_QUIT) close();
        if (e.type == SDL_KEYDOWN)  {
            if (e.key.keysym.sym == SDLK_ESCAPE)    close();
            if (e.key.keysym.sym == SDLK_LEFT)      deltaX = -1;
            if (e.key.keysym.sym == SDLK_RIGHT)     deltaX =  1;
            if (e.key.keysym.sym == SDLK_DOWN)      delay = 50;
            if (e.key.keysym.sym == SDLK_UP)        Rotate = 1;

            if (e.key.keysym.sym == SDLK_a) Rotate = -1;
            if (e.key.keysym.sym == SDLK_s) Rotate =  1;

            if (e.key.keysym.sym == SDLK_SPACE) {
                Score += To_The_Filled_Zone;

                new_X = simulateX;
                new_Y = simulateY;

                if(!Landing())  return  false;
                goto out;
            }
            if (e.key.keysym.sym == SDLK_c && C_is_pressed == false)    {
                C_is_pressed = true;
                Hold();
            }
        }
        push();
        roll();
    }
    if (timer > delay)  {
        timer = 0;

        for(int i = 0 ; i < 4 ; ++i)    {
            new_X[i] = current_posX[i];
            new_Y[i] = current_posY[i] + 1;
        }
        if(!check())    {
            for(int&y : new_Y)  y--;

            if(!Landing())
                return  false;
        }
        else if (delay == 50)
            Score++;
    }
    out:;
    delay = DEFAULT_SPEED;

    int line_get_this_turn = checkLine();

    if (line_get_this_turn) {
        Lines += line_get_this_turn;
        Score += line_get_this_turn * 20 - 10;
    }

    for(int i = 0 ; i < BOARD_HEIGHT ; ++i)
    for(int j = 0 ; j < BOARD_WIDTH  ; ++j)
        draw(j,i,color[Filled[i][j]]);

    drawVirtualResult();

    for(int i = 0 ; i < 4 ; ++i)
        draw(current_posX[i],current_posY[i],color[index]);

    draw_NextTiles();
    draw_HeldTiles();
    drawBoard();

    update_Status();

    SDL_RenderPresent(renderer);

    return  true;
}
