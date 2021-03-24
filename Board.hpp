#pragma once
#include <string>
#include <iostream>
#include "Direction.hpp"
#include <vector>
using namespace std;
using ariel::Direction;

namespace ariel {
    class Board {
    private:
        int row;
        int col;
        vector<vector<char>> board;
    public:
        // Board() {
        //     board = vector<vector<char>>(10, vector<char>(10, '_'));
        // };
        void post(unsigned int row, unsigned int col, Direction dr, string word);
        string read(unsigned int row, unsigned int col, Direction dr, unsigned int length);
        void show();
    };
}