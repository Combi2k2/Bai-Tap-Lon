int Score = 0;
int Lines = 0;
int Level = 1;
int DEFAULT_SPEED = 800;

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

void update_Status()    {
    Level = Score / 200;    DEFAULT_SPEED = 800 - Level * 50;
    Level++;

    //delete old status

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect Zone = {405, 480, SCREEN_WIDTH - 405, SCREEN_HEIGHT - 480};

    SDL_RenderFillRect(renderer, &Zone);

    //

    write_Score();
    write_Lines();
    write_Level();
}
