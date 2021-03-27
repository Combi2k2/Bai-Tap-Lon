void drawTriangle(int x,int y, vector<int> col = WHITE) {
    SetDrawColor(col);

    for(int i = 0 ; i < 30 ; ++i)
    for(int j = 0 ; j <= i ; ++j)
        SDL_RenderDrawPoint(renderer, x + j, y + i);

    y += 59;

    for(int i = 0 ; i < 30 ; ++i)
    for(int j = 0 ; j <= i ; ++j)
        SDL_RenderDrawPoint(renderer, x + j, y - i);
}
bool Pause()    {
    SDL_Rect Zone;

    SetDrawColor(WHITE);    Zone = {135, 200, 400, 300};    SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {140, 205, 390, 290};    SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(WHITE);

    write("RESUME", 230, 270, 50);
    write("REPLAY", 230, 370, 50);

    drawTriangle(180, 270);

    SDL_RenderPresent(renderer);
    SDL_Event e;

    bool Option = 0;

    while (true)    {
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT)     close();
        if (e.type == SDL_KEYDOWN)  {
            if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)   return  Option ^ 1;
            bool change = false;
            if (e.key.keysym.sym == SDLK_UP)    change = true;
            if (e.key.keysym.sym == SDLK_DOWN)  change = true;

            if (change) {
                Option ^= 1;

                if (Option) {
                    drawTriangle(180, 370);
                    drawTriangle(180, 270, BLACK);
                }
                else    {
                    drawTriangle(180, 270);
                    drawTriangle(180, 370, BLACK);
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
}
