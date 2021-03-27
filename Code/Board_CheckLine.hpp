int checkLine() {
    int S = 0;
    int k = BOARD_HEIGHT - 1;

    for(int i = k ; i >= 0 ; --i)   {
        int cnt = 0;

        for(int j = 0 ; j < BOARD_WIDTH ; ++j)  {
            cnt +=        (Filled[i][j] != 0);
            Filled[k][j] = Filled[i][j];
        }
        if (cnt < BOARD_WIDTH) k--;
        else    S++;
    }
    for(; k >= 0 ; --k)
        fill(Filled[k],Filled[k] + BOARD_WIDTH,0);

    return  S;
}
