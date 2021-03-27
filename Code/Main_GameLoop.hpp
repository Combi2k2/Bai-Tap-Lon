int timer = 0;
int delay = DEFAULT_SPEED;
int time_elapsed;

SDL_Event e;
bool pressC = false;

bool Landing()  {
    for(int i = 0 ; i < 4 ; ++i)    if (newY[i] < 0)    return  false;
    for(int i = 0 ; i < 4 ; ++i)    Filled[newY[i]][newX[i]] = index;

    spawn();
    pressC = false;

    return  true;
}
bool gameLoop() {
    timer += clock() - time_elapsed;
    time_elapsed = clock();

    if (SDL_PollEvent(&e))  {
        if (e.type == SDL_QUIT) close();
        if (e.type == SDL_KEYDOWN)  {
            if (e.key.keysym.sym == SDLK_ESCAPE)    close();
            if (e.key.keysym.sym == SDLK_LEFT)      deltaX--;
            if (e.key.keysym.sym == SDLK_RIGHT)     deltaX++;
            if (e.key.keysym.sym == SDLK_DOWN)      delay = 50;
            if (e.key.keysym.sym == SDLK_UP)        Rotate = 1;

            if (e.key.keysym.sym == SDLK_a) Rotate = -1;
            if (e.key.keysym.sym == SDLK_s) Rotate =  1;

            if (e.key.keysym.sym == SDLK_SPACE) {
                newX = current_posX;
                newY = current_posY;    for(int&y : newY)   y += dist;

                if(!Landing())  return  false;
                else            Score += dist;
                goto out;
            }
            if (e.key.keysym.sym == SDLK_p) {
                if (Pause())    {
                    time_elapsed = clock();
                    return  true;
                }
                return  false;
            }
            if (e.key.keysym.sym == SDLK_c)
                if(!pressC) {
                    pressC = true;
                    Hold();
                }
        }
        push();
        roll();
    }
    if (timer > delay)  {
        timer = 0;

        for(int i = 0 ; i < 4 ; ++i)    {
            newX[i] = current_posX[i];
            newY[i] = current_posY[i] + 1;
        }
        if(!check())    {
            for(int&y : newY)   y--;

            if(!Landing())
                return  false;
        }
        else    Score += (delay == 50);
    }
    out:;
    delay = DEFAULT_SPEED;

    int line_get_this_turn = checkLine();

    if (line_get_this_turn) {
        Lines += line_get_this_turn;
        Score += line_get_this_turn * 20 - 10;
    }

    drawBoard();
    draw_Dest();
    draw_Next();
    draw_Hold();

    for(int i = 0 ; i < 4 ; ++i)    {
        int x = current_posX[i];
        int y = current_posY[i];

        if (y >= 0)
            drawSquare(x * 30 + 50, y * 30 + 50, color[index]);
    }
    write_Score();
    write_Lines();
    write_Level();

    SDL_RenderPresent(renderer);

    return  true;
}
