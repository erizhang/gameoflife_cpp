
#include <string>

using std::string;

class Cell{
 public:
    Cell(int x, int y, bool alive);
    ~Cell(){}
 private:
    int pos_x;
    int pos_y;
    bool alive;
};

class Game{
 public:
    Game(int w, int h, string layout);
    Game(){}
    ~Game(){}
    string nextGeneration();

 private:
    int m_width;
    int m_height;
    string m_gameLayout;
};


