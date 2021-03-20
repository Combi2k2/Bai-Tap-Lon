#include <bits/stdc++.h>

using namespace std;

int checkLine() {
    int score = 0;
    int k = BOARD_HEIGHT - 1;

    for(int i = BOARD_HEIGHT - 1 ; i >= 0 ; --i)    {
        int cnt = 0;
        for(int j = 0 ; j < BOARD_WIDTH ; ++j)  {
            if (Filled[i][j])   cnt++;
                Filled[k][j] = Filled[i][j];
        }
        if (cnt < BOARD_WIDTH)  k--;
        else    score++;
    }
    for(; k >= 0 ; --k)
        fill(Filled[k],Filled[k] + BOARD_WIDTH,0);

    return  score;
}
