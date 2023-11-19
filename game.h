#ifndef __GAME__
#define __GAME__
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class Game {
    private:
        int grid[8][10] = { 0 };
        int gridToPrint[8][10] = { 0 };
        bool gameOver;
        int uncoveredSquares;
        string mainMenu();
        string rules();
        void executeGame();
        void generateGrid(int, int);
        bool validMineIndex(int, int, int, int);
        bool validIndex(int, int);
        void revealChoice(int, int);
        void printGrid(bool);
        void printNumbers(int num, string& output1, string& output2, string& output3, bool inGrid);
    public:
        Game();
        void startGame();
};

#endif
