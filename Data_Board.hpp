#include <bits/stdc++.h>

SDL_Rect Main_board;

void drawBoard()    {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    Main_board = {49,49,301,601};   SDL_RenderDrawRect(renderer,&Main_board);
    Main_board = {45,45,309,609};   SDL_RenderDrawRect(renderer,&Main_board);
}
