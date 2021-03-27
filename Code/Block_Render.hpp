void drawSquare(int x,int y,vector<int> col)    {
    SDL_Rect Combi;
    SetDrawColor(col);

    Combi.x = x;
    Combi.y = y;
    Combi.h = Combi.w = 29;

    SDL_RenderFillRect(renderer, &Combi);

    if (col != BLACK)   {
        SetDrawColor(WHITE);    Combi = {x + 3, y + 3, 23, 23};     SDL_RenderFillRect(renderer, &Combi);
        SetDrawColor(col);      Combi = {x + 6, y + 6, 17, 17};     SDL_RenderFillRect(renderer, &Combi);
    }
}
