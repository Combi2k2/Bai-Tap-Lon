void draw_Next()    {
    SDL_Rect Zone;

    SetDrawColor(WHITE);    Zone = {405,45,219,189};    SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {410,50,209,179};    SDL_RenderFillRect(renderer, &Zone);

    SetDrawColor(WHITE);    Zone = {405,25, 80, 40};    SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {410,30, 70, 30};    SDL_RenderFillRect(renderer, &Zone);

    write("NEXT", 412, 30);

    for(int i = 0 ; i < 2 ; ++i)    {
        int id = Tile_queue[i];

        for(int j = 0 ; j < 4 ; ++j)    {
            int x = Pos[id][j] % 2 + 13 + i * 3;
            int y = Pos[id][j] / 2 + 1;

            drawSquare(x * 30 + 50,y * 30 + 50,color[id]);
        }
    }
}
