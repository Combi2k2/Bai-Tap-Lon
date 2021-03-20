#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "InitWindow.hpp"
#include "Render_Text.hpp"

#include "Data_Blocks.hpp"
#include "Data_Board.hpp"
#include "Data_NextTiles.hpp"
#include "Data_HeldBlock.hpp"

#include "Logic_Blocks.hpp"
#include "Logic_Simulate.hpp"
#include "Logic_LineCheck.hpp"
#include "Logic_Status.hpp"

#include "GameLoop.hpp"

using namespace std;

void startGame()    {
    SDL_Surface* start = SDL_LoadBMP("Background.bmp");
    SDL_BlitSurface(start,NULL,SDL_GetWindowSurface(window),NULL);
    SDL_UpdateWindowSurface(window);

    SDL_Event e;

    while (true)    {
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT)     close();
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            break;
    }
}

int main(int argc,char **argv)  {
    startProgram();
    startGame();

    while (true)    {
        time_elapsed = clock();
        spawnTile();

        while (gameLoop());

        cerr << "END TURN\n";

        //Print the result after game end

        SDL_Rect GameEnd;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        GameEnd = {135, 200, 400, 300}; SDL_RenderFillRect(renderer, &GameEnd); SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        GameEnd = {140, 205, 390, 290}; SDL_RenderFillRect(renderer, &GameEnd);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        string FINAL_SCORE = to_string(Score);

        while (FINAL_SCORE.size() < 4)
            FINAL_SCORE = "0" + FINAL_SCORE;

        write("YOUR FINAL SCORE IS:", 190, 250);
        write(FINAL_SCORE, 280, 300, 50);
        write("Press space to replay", 250, 400, 18);

        SDL_RenderPresent(renderer);

        //wait for key space so next turn can start

        SDL_Event e;

        while (true)    {
            if (SDL_WaitEvent(&e) == 0) continue;
            if (e.type == SDL_QUIT)     close();
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
                break;
        }
        //reset all the information of the game

        GameEnd = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &GameEnd);

        memset(Filled, 0, sizeof Filled);

        Held = -1;
        Size = 0;

        Score = 0;
        Lines = 0;
        Level = 0;
    }
}
