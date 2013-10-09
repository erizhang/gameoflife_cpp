
#include <string>

using std::string;

class Game{
public:
    Game(int w, int h, string layout);
    Game(){}
    ~Game(){}
    string nextGeneration();

private:
    int width;
    int height;
};


