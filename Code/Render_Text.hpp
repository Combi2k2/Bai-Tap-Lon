void write(string Content,int x,int y,int Size = 25)    {
    SDL_Color color = { 255, 255, 255 };

    font = TTF_OpenFont("Font/arial.ttf",Size);

    surface = TTF_RenderText_Solid(font, Content.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { x, y, texW, texH };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}
