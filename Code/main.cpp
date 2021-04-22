#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "InitWindow.hpp"

#include "Tiles_Data.hpp"
#include "Tiles_Generate.hpp"
#include "Tiles_Logic.hpp"

#include "Block_Render.hpp"
#include "Board_Render.hpp"
#include "Board_CheckLine.hpp"

#include "Prediction_Render.hpp"

#include "Status_Data.hpp"
#include "Status_Render.hpp"

#include "Tiles_Next.hpp"
#include "Tiles_Hold.hpp"

#include "Game_Pause.hpp"
#include "Game_End.hpp"

#include "Main_GameLoop.hpp"

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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        printf("%s", Mix_GetError());

    Mix_Music* music = Mix_LoadMUS("TetrisGameBoy-V.A-3323727.mp3");
    Mix_PlayMusic(music, -1);

    while (true)    {
        time_elapsed = clock();
        spawn();

        while (gameLoop());

        draw_End();
    }
}

