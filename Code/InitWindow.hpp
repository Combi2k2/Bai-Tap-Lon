#include <bits/stdc++.h>

using namespace std;

void logSDLError(ostream& os,const string &msg, bool fatal = false) {
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)  {
        SDL_Quit();
        exit(1);
    }
}
//Screen dimension constants
const int SCREEN_WIDTH  = 670;
const int SCREEN_HEIGHT = 700;

const string WINDOW_TITLE = "Tetris by Combi";

SDL_Window*   window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Surface * surface = NULL;
SDL_Texture * texture = NULL;

TTF_Font * font = NULL;

void startProgram() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("Tetris by Combi",
             SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
}
void close()    {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    TTF_CloseFont(font);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

