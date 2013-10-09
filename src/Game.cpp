#include <iostream>
#include "Game.h"
using namespace std;
using std::string;

Cell::Cell(int x, int y, bool alive)
{
    this->pos_x = x;
    this->pos_y = y;
    this->alive = alive;
}

Game::Game(int w, int h, string layout)
{
    this->m_width = w;
    this->m_height = h;
    this->m_gameLayout = layout;
}

string Game::nextGeneration()
{
    return "000000000";
}


