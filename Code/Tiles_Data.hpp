const vector<int> CYAN    = {0, 255, 255};
const vector<int> BLUE    = {0, 0, 255};
const vector<int> ORANGE  = {255, 165, 0};
const vector<int> YELLOW  = {255, 255, 0};
const vector<int> LIME    = {0, 255, 0};
const vector<int> PURPLE  = {128, 0, 128};
const vector<int> RED     = {255, 0, 0};
const vector<int> WHITE   = {255, 255, 255};
const vector<int> BLACK   = {0, 0, 0};
const vector<int> GREEN   = {0, 128, 0};

#define SetDrawColor(x) SDL_SetRenderDrawColor(renderer, x[0], x[1], x[2], 255)

vector<int> Pos[] = {{},
                     {1,3,5,7},     //I
                     {2,4,5,7},     //Z
                     {3,5,4,6},     //S
                     {3,5,4,7},     //T
                     {2,5,3,7},     //L
                     {3,5,7,6},     //J
                     {2,3,4,5}};    //O
vector<int> color[] = {BLACK,
                       CYAN,
                       GREEN,
                       RED,
                       PURPLE,
                       BLUE,
                       ORANGE,
                       YELLOW};
