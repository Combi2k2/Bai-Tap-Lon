void write(string Content,int x,int y,int Size = 25,vector<int> col = WHITE)    {
    font = TTF_OpenFont("Font/arial.ttf",Size);

    SDL_Color Col = {col[0], col[1], col[2]};

    surface = TTF_RenderText_Solid(font, Content.c_str(), Col);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { x, y, texW, texH };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}
void write_Score()  {
    write("SCORE:", 405, 480);
    write(to_string(Score), 550, 480);
}
void write_Lines()  {
    write("LINES:", 405, 520);
    write(to_string(Lines), 550, 520);
}
void write_Level()  {
    write("LEVEL:", 405, 560);
    write(to_string(Level), 550, 560);
}
