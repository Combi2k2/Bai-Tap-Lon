const int   BOARD_WIDTH     = 10;
const int   BOARD_HEIGHT    = 20;

int Filled[BOARD_HEIGHT][BOARD_WIDTH];

vector<int> newX(4);
vector<int> newY(4);

bool check()    {
    for(int i = 0 ; i < 4 ; ++i)    {
        if (newX[i] < 0)    return  false;
        if (newX[i] >= BOARD_WIDTH)     return  false;
        if (newY[i] >= BOARD_HEIGHT)    return  false;
        if (newY[i] < 0)    continue;

        if (Filled[newY[i]][newX[i]])
            return  false;
    }
    current_posX = newX;
    current_posY = newY;

    return  true;
}
int deltaX = 0;
int Rotate = 0;

void push() {
    for(int i = 0 ; i < 4 ; ++i)
        newX[i] = current_posX[i] + deltaX,
        newY[i] = current_posY[i];

    deltaX = 0;
    check();
}
void roll() {
    if (Rotate == 0 || index == 7)  {
        newX = current_posX;
        newY = current_posY;
        return;
    }
    for(int i = 0 ; i < 4 ; ++i)    {
        int dx = current_posX[i] - current_posX[1];
        int dy = current_posY[i] - current_posY[1];

        int nX = current_posX[1];
        int nY = current_posY[1];

        if (Rotate > 0)    nX += dy, nY -= dx;
        if (Rotate < 0)    nX -= dy, nY += dx;

        newX[i] = nX;
        newY[i] = nY;
    }
    Rotate = 0;

    vector<int> vec = {0,1,-1,2,-2};

    for(int offset : vec)   {
        for(int&x : newX)   x += offset;    if (check())    return;
        for(int&x : newX)   x -= offset;
    }
}
void Hold() {
    if (Held < 0)   {
        Held = index;
        spawn();
    }
    else    {
        current_posX.clear();
        current_posY.clear();

        for(int i = 0 ; i < 4 ; ++i)    {
            current_posX.push_back(Pos[Held][i] % 2 + 4);
            current_posY.push_back(Pos[Held][i] / 2 - 3);
        }

        swap(Held,index);
    }
}
