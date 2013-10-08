
#include <string>

using std::string;

class Game{
public:
    Game(int w, int h, string layout);
    Game(){}
    ~Game(){}
    int verify_ut(int i, int j) {
        return i + j;
    }

private:
    int width;
    int height;
};


