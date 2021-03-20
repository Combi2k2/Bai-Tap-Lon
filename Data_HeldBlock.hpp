void draw_HeldTiles()   {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect Zone;

    Zone = {405,265,219,189};   SDL_RenderFillRect(renderer, &Zone);    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    Zone = {410,270,209,179};   SDL_RenderFillRect(renderer, &Zone);    write("HOLD",480,270);

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

    int Center_X = Zone.x + Zone.h / 2;
    int Center_Y = Zone.y + Zone.w / 2;

    int Offset_X = Center_X - (r + l + 1) * 15;// - l * 30;
    int Offset_Y = Center_Y - (u + d + 1) * 15;

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = Pos[Held][i] / 2;
        int y = Pos[Held][i] % 2;

        x = x * 30 + Offset_X;
        y = y * 30 + Offset_Y;

        drawSquare(x,y,color[Held]);
    }
}
