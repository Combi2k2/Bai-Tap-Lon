mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> current_posX;
vector<int> current_posY;

int index;
int Tile_queue[3];
int Size = 0;

int Held = -1;

void spawn()    {
    while (Size < 3)    {
        int idx = rand() % 7 + 1;
        if (idx < 1)
            idx += 7;

        Tile_queue[Size++] = idx;
    }
    index = Tile_queue[0];

    Tile_queue[0] = Tile_queue[1];
    Tile_queue[1] = Tile_queue[2];  Size = 2;

    current_posX.clear();
    current_posY.clear();

    for(int i = 0 ; i < 4 ; ++i)    {
        current_posX.push_back(Pos[index][i] % 2 + 4);
        current_posY.push_back(Pos[index][i] / 2 - 3);
    }
}
