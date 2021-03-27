int dist = 0;

void draw_Dest()    {
    dist = BOARD_HEIGHT;

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = current_posX[i];
        int y = current_posY[i];

        for(; y < BOARD_HEIGHT - 1 ; ++y)
            if (y >= -1 && Filled[y + 1][x])
                break;

        if (dist > y - current_posY[i])
            dist = y - current_posY[i];
    }
    for(int i = 0 ; i < 4 ; ++i)    {
        int x = current_posX[i];
        int y = current_posY[i] + dist;

        if (y < 0)  continue;

        SDL_Rect Combi = {x * 30 + 50, y * 30 + 50, 29, 29};    SetDrawColor(color[index]);
        SDL_RenderDrawRect(renderer, &Combi);
    }
}
