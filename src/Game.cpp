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

bool Cell::isAlive()
{
    return this->alive;
}

void Cell::Live()
{
    this->alive = true;
}

void Cell::Die()
{
    this->alive = false;
}

int Cell::X()
{
    return this->pos_x;
}

int Cell::Y()
{
    return this->pos_y;
}







Game::Game(int w, int h, string layout)
{
    this->m_width = w;
    this->m_height = h;
    this->m_gameLayout = layout;

    this->constructOffset();
    //this->saveCells();
}

Game::~Game()
{
    this->emptyCells();
}

void Game::saveCells()
{
    int x = 0;
    int y = 0;
    int pos = 0;
    char c;

    for (y = 0; y < this->m_height; y++){
        for (x = 0; x < this->m_width; x++) {
            Cell *cell = new Cell(x, y, false);

            pos = y * this->m_height + x;
            c = this->m_gameLayout.at(pos);
            if (c == '1') {
                cell->Live();
            }
            this->cells.push_back(cell);

        }

    }
}

void Game::emptyCells()
{
    vector<Cell*>::iterator iter;
    for (iter = this->cells.begin(); iter != this->cells.end(); iter++) {
        Cell *cell = *iter;
        if (cell != NULL) {
            delete cell;
        }
        cell = NULL;
    }
    this->cells.clear();
}

void Game::constructOffset()
{
    int i, j;
    for (i = -1; i < 2; i++) {
        for (j = -1; j <2; j++) {
            vector<int> elem;
            elem.push_back(i);
            elem.push_back(j);
            this->neighbour_offset.push_back(elem);
        }
    }
    this->neighbour_offset.erase(this->neighbour_offset.begin() + 4);
}

bool Game::isAliveNeighbour(int x, int y)
{
    if (x < 0 || x >= this->m_width ||
        y < 0 || y >= this->m_height)
    {
        return false;
    }
    int pos = y * this->m_height + x;
    char c = m_gameLayout.at(pos);
    if (c == '1') {
        return true;
    }
    return false;
}

int Game::neighbourCount(int x, int y)
{
    int count = 0;
    vector< vector<int> >::iterator iter;
    for (iter = this->neighbour_offset.begin(); 
         iter != this->neighbour_offset.end(); iter++) {

        int pos_x = x + (*iter)[0];
        int pos_y = y + (*iter)[1];

        if (this->isAliveNeighbour(pos_x, pos_y)) {
            count++;
        }
    }
    return count;
}

void Game::render()
{
    string output = "";
    vector<Cell*>::iterator iter;

    for (iter = this->cells.begin(); iter != this->cells.end(); iter++) {
        Cell *cell = *iter;
        if (cell->isAlive()) {
            output += "1";
        }
        else {
            output += "0";
        }
    }
    this->m_gameLayout = output;
}

string Game::nextGeneration()
{
    this->saveCells();

    int count = 0;
    vector<Cell*>::iterator iter;

    for (iter = this->cells.begin(); iter != this->cells.end(); iter++) {
        Cell *cell = *iter;
        count = neighbourCount(cell->X(), cell->Y());
        if (count < 2 || count > 3) {
            cell->Die();
        }
    }
    this->render();

    return m_gameLayout;
}


