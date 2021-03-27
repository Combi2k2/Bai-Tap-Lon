void draw_Hold()    {
    SDL_Rect Zone;

    SetDrawColor(WHITE);    Zone = {405,265,219,189};   SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {410,270,209,179};   SDL_RenderFillRect(renderer, &Zone);

    SetDrawColor(WHITE);    Zone = {405,245, 80, 40};   SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {410,250, 70, 30};   SDL_RenderFillRect(renderer, &Zone);

    write("HOLD", 411, 250);

    if (Held < 0)
        return;

    int l = 3, r = 0;
    int u = 1, d = 0;

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = Pos[Held][i] / 2;
        int y = Pos[Held][i] % 2;

        l = min(l,x);   r = max(r,x);
        u = min(u,y);   d = max(d,y);
    }

    int Offset_X = 514 - (r + l + 1) * 15;// - l * 30;
    int Offset_Y = 359 - (u + d + 1) * 15;

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = Pos[Held][i] / 2;
        int y = Pos[Held][i] % 2;

        x = x * 30 + Offset_X;
        y = y * 30 + Offset_Y;

        drawSquare(x,y,color[Held]);
    }
}

