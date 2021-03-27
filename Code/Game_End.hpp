void draw_End() {
    cerr << "END TURN\n";

    //Print the result after game end

    SDL_Rect Zone;

    SetDrawColor(WHITE);    Zone = {135, 200, 400, 300};    SDL_RenderFillRect(renderer, &Zone);
    SetDrawColor(BLACK);    Zone = {140, 205, 390, 290};    SDL_RenderFillRect(renderer, &Zone);

    string FINAL_SCORE = to_string(Score);

    while (FINAL_SCORE.size() < 4)
        FINAL_SCORE = "0" + FINAL_SCORE;

    write("YOUR FINAL SCORE IS:", 190, 250);
    write(FINAL_SCORE, 280, 300, 50);
    write("Press space to replay", 250, 400, 18);

    SDL_RenderPresent(renderer);

    //wait for key space so next turn can start

    SDL_Event e;

    while (true)    {
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT)     close();
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            break;
    }
    //reset all the information of the game

    Zone = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_RenderFillRect(renderer, &Zone);

    memset(Filled, 0, sizeof Filled);

    Held = -1;
    Size = 0;

    Score = 0;
}
