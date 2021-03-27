void drawBoard()    {
    SDL_Rect Main_board;

    SetDrawColor(BLACK);    Main_board = {0, 0, 670,700};   SDL_RenderFillRect(renderer,&Main_board);

    SetDrawColor(WHITE);    Main_board = {44,44,311,611};   SDL_RenderFillRect(renderer,&Main_board);
    SetDrawColor(BLACK);    Main_board = {49,49,301,601};   SDL_RenderFillRect(renderer,&Main_board);

    for(int i = 0 ; i < BOARD_HEIGHT ; ++i)
    for(int j = 0 ; j < BOARD_WIDTH  ; ++j) {
        int x = j * 30 + 50;
        int y = i * 30 + 50;

        drawSquare(x, y, color[Filled[i][j]]);
    }
}
