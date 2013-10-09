
#include <string>
#include <vector>

using std::vector;
using std::string;

class Cell{
 public:
    Cell(int x, int y, bool alive);
    ~Cell(){}
    void Live();
    void Die();
    bool isAlive();
    Cell &operator=(Cell &rcell){
        return rcell;
    }
    int X();
    int Y();
 private:
    int pos_x;
    int pos_y;
    bool alive;
};

class Game{
 public:
    Game(int w, int h, string layout);
    Game(){}
    ~Game();
    string nextGeneration();
    void debugCells();
 private:
    void initCells();
    bool isAliveNeighbour(int x, int y);
    int neighbourCount(int x, int y);
    void constructOffset();
    void saveCells();
    void render();// Store cells to m_gameLayout;
    void emptyCells();
 private:
    vector<Cell*> cells;
    int m_width;
    int m_height;
    string m_gameLayout;
    vector< vector<int> > neighbour_offset;
};


