#include "game.h"

Game::Game(){
    gameOver = false;
    uncoveredSquares = 0;
}

void Game::startGame() {
    string choice = mainMenu();
    while(!gameOver) {
        if(choice == "1") {
            executeGame();
        }
        else if(choice == "2") {
            choice = rules();
        }
        else if(choice == "return") {
            choice = mainMenu();
        }
    }

    printGrid(true);
    if(uncoveredSquares == 70) {
        cout << "\n";
        cout << "░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗░░░\n";
        cout << "██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝░░░\n";
        cout << "██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░░░░\n";
        cout << "██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗██╗\n";
        cout << "╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝╚█║\n";
        cout << "░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░░╚╝\n";
        cout << "\n";
        cout << "██╗░░░██╗░█████╗░██╗░░░██╗  ░██████╗░█████╗░██╗░░░██╗███████╗██████╗░  ████████╗██╗░░██╗███████╗\n";
        cout << "╚██╗░██╔╝██╔══██╗██║░░░██║  ██╔════╝██╔══██╗██║░░░██║██╔════╝██╔══██╗  ╚══██╔══╝██║░░██║██╔════╝\n";
        cout << "░╚████╔╝░██║░░██║██║░░░██║  ╚█████╗░███████║╚██╗░██╔╝█████╗░░██║░░██║  ░░░██║░░░███████║█████╗░░\n";
        cout << "░░╚██╔╝░░██║░░██║██║░░░██║  ░╚═══██╗██╔══██║░╚████╔╝░██╔══╝░░██║░░██║  ░░░██║░░░██╔══██║██╔══╝░░\n";
        cout << "░░░██║░░░╚█████╔╝╚██████╔╝  ██████╔╝██║░░██║░░╚██╔╝░░███████╗██████╔╝  ░░░██║░░░██║░░██║███████╗\n";
        cout << "░░░╚═╝░░░░╚════╝░░╚═════╝░  ╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝\n";
        cout << "\n";
        cout << "███████╗██╗░██████╗██╗░░██╗░░░\n";
        cout << "██╔════╝██║██╔════╝██║░░██║░░░\n";
        cout << "█████╗░░██║╚█████╗░███████║░░░\n";
        cout << "██╔══╝░░██║░╚═══██╗██╔══██║░░░\n";
        cout << "██║░░░░░██║██████╔╝██║░░██║██╗\n";
        cout << "╚═╝░░░░░╚═╝╚═════╝░╚═╝░░╚═╝╚═╝\n";
        cout << "\n";
    }
    else {
        cout << "\n";
        cout << "██╗░░░██╗░█████╗░██╗░░░██╗  ██╗░░██╗██╗██╗░░░░░██╗░░░░░███████╗██████╗░  ████████╗██╗░░██╗███████╗\n";
        cout << "╚██╗░██╔╝██╔══██╗██║░░░██║  ██║░██╔╝██║██║░░░░░██║░░░░░██╔════╝██╔══██╗  ╚══██╔══╝██║░░██║██╔════╝\n";
        cout << "░╚████╔╝░██║░░██║██║░░░██║  █████═╝░██║██║░░░░░██║░░░░░█████╗░░██║░░██║  ░░░██║░░░███████║█████╗░░\n";
        cout << "░░╚██╔╝░░██║░░██║██║░░░██║  ██╔═██╗░██║██║░░░░░██║░░░░░██╔══╝░░██║░░██║  ░░░██║░░░██╔══██║██╔══╝░░\n";
        cout << "░░░██║░░░╚█████╔╝╚██████╔╝  ██║░╚██╗██║███████╗███████╗███████╗██████╔╝  ░░░██║░░░██║░░██║███████╗\n";
        cout << "░░░╚═╝░░░░╚════╝░░╚═════╝░  ╚═╝░░╚═╝╚═╝╚══════╝╚══════╝╚══════╝╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝\n";
        cout << "\n";
        cout << "███████╗██╗░██████╗██╗░░██╗░░░  ░██╗░░░░░░░██╗██╗░░██╗░█████╗░████████╗  ██╗░██████╗\n";
        cout << "██╔════╝██║██╔════╝██║░░██║░░░  ░██║░░██╗░░██║██║░░██║██╔══██╗╚══██╔══╝  ██║██╔════╝\n";
        cout << "█████╗░░██║╚█████╗░███████║░░░  ░╚██╗████╗██╔╝███████║███████║░░░██║░░░  ██║╚█████╗░\n";
        cout << "██╔══╝░░██║░╚═══██╗██╔══██║██╗  ░░████╔═████║░██╔══██║██╔══██║░░░██║░░░  ██║░╚═══██╗\n";
        cout << "██║░░░░░██║██████╔╝██║░░██║╚█║  ░░╚██╔╝░╚██╔╝░██║░░██║██║░░██║░░░██║░░░  ██║██████╔╝\n";
        cout << "╚═╝░░░░░╚═╝╚═════╝░╚═╝░░╚═╝░╚╝  ░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░  ╚═╝╚═════╝░\n";
        cout << "\n";
        cout << "░██╗░░░░░░░██╗██████╗░░█████╗░███╗░░██╗░██████╗░  ░██╗░░░░░░░██╗██╗████████╗██╗░░██╗  ██╗░░░██╗░█████╗░██╗░░░██╗░░░\n";
        cout << "░██║░░██╗░░██║██╔══██╗██╔══██╗████╗░██║██╔════╝░  ░██║░░██╗░░██║██║╚══██╔══╝██║░░██║  ╚██╗░██╔╝██╔══██╗██║░░░██║░░░\n";
        cout << "░╚██╗████╗██╔╝██████╔╝██║░░██║██╔██╗██║██║░░██╗░  ░╚██╗████╗██╔╝██║░░░██║░░░███████║  ░╚████╔╝░██║░░██║██║░░░██║░░░\n";
        cout << "░░████╔═████║░██╔══██╗██║░░██║██║╚████║██║░░╚██╗  ░░████╔═████║░██║░░░██║░░░██╔══██║  ░░╚██╔╝░░██║░░██║██║░░░██║░░░\n";
        cout << "░░╚██╔╝░╚██╔╝░██║░░██║╚█████╔╝██║░╚███║╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║░░░██║░░░██║░░██║  ░░░██║░░░╚█████╔╝╚██████╔╝██╗\n";
        cout << "░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚══╝░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝  ░░░╚═╝░░░░╚════╝░░╚═════╝░╚═╝\n";
        cout << "\n";
    }
    gameOver = true;
}

string Game::mainMenu() {
    system("clear");
    
    cout << "░██████╗░█████╗░██╗░░░██╗███████╗  ████████╗██╗░░██╗███████╗  ███████╗██╗░██████╗██╗░░██╗\n";
    cout << "██╔════╝██╔══██╗██║░░░██║██╔════╝  ╚══██╔══╝██║░░██║██╔════╝  ██╔════╝██║██╔════╝██║░░██║\n";
    cout << "╚█████╗░███████║╚██╗░██╔╝█████╗░░  ░░░██║░░░███████║█████╗░░  █████╗░░██║╚█████╗░███████║\n";
    cout << "░╚═══██╗██╔══██║░╚████╔╝░██╔══╝░░  ░░░██║░░░██╔══██║██╔══╝░░  ██╔══╝░░██║░╚═══██╗██╔══██║\n";
    cout << "██████╔╝██║░░██║░░╚██╔╝░░███████╗  ░░░██║░░░██║░░██║███████╗  ██║░░░░░██║██████╔╝██║░░██║\n";
    cout << "╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░░░░╚═╝╚═════╝░╚═╝░░╚═╝\n\n\n\n";

    cout << "█▀█ █░░ ▄▀█ █▄█   ▄▀ █▀▀ █▄░█ ▀█▀ █▀▀ █▀█   ▄█ ▀▄\n";
    cout << "█▀▀ █▄▄ █▀█ ░█░   ▀▄ ██▄ █░▀█ ░█░ ██▄ █▀▄   ░█ ▄▀\n\n\n";

    cout << "█▀█ █░█ █░░ █▀▀ █▀   ▄▀ █▀▀ █▄░█ ▀█▀ █▀▀ █▀█   ▀█ ▀▄\n";
    cout << "█▀▄ █▄█ █▄▄ ██▄ ▄█   ▀▄ ██▄ █░▀█ ░█░ ██▄ █▀▄   █▄ ▄▀\n\n\n";

    string input;
    cin >> input;
    while(input != "1" && input != "2") {
        cout << "Please enter valid input\n";
        cin >> input;
    }

    return input;
}

string Game::rules() {
    system("clear");

    string output;

    cout << "██████╗░██╗░░░██╗██╗░░░░░███████╗░██████╗\n";
    cout << "██╔══██╗██║░░░██║██║░░░░░██╔════╝██╔════╝\n";
    cout << "██████╔╝██║░░░██║██║░░░░░█████╗░░╚█████╗░\n";
    cout << "██╔══██╗██║░░░██║██║░░░░░██╔══╝░░░╚═══██╗\n";
    cout << "██║░░██║╚██████╔╝███████╗███████╗██████╔╝\n";
    cout << "╚═╝░░╚═╝░╚═════╝░╚══════╝╚══════╝╚═════╝░\n\n\n";

    output += "Your goal is to remove as much trash as you can from the ocean without accidently removing and killing any marine animals. This is very similar to Minesweeper where hitting an animal instantly means you lose.\n";
    output += "\n";
    output += "In Minesweeper, hidden mines are scattered throughout a board, which is divided into cells. Cells have multiple possible states:\n";
    output += "\t- Unopened tiles (cover the board at the start of the game, can also be made by removing flags)\n";
    output += "\t- Numbered tiles (can show 1-8)\n";
    output += "\t- Blank tiles (shown as 0 in this game, no mines are on the diagonal/adjacent to the tile)\n";
    //output += "\t- Flagged tiles (right-clicking an unopened tile)\n";
    output += "\t- Unmarked tiles (right-clicking a flagged tile; only exists in certain implementations)\n";
    output += "\n";
    output += "An unopened cell is blank and clickable, while an opened cell is exposed. Flagged cells are unopened cells marked by the player to indicate a potential mine location; some implementations make flagged cells unopenable to reduce the risk of uncovering a suspected mine.\n";
    output += "\n";
    output += "A player selects a cell to open it. If a player opens a cell containing a mine, the game ends in a loss. Otherwise, the opened cell displays either a number, indicating the number of mines diagonally and/or adjacent to it, or a blank tile (sometimes shown as a 0), and all adjacent cells will automatically be opened. This may cause a chain reaction; any blank tiles opened by other blank tiles open the surrounding tiles too. Players can also flag a cell, visualised by a flag being put on the tile, to denote that they believe a mine to be in that place. Flagged cells are still considered unopened, and may be unflagged.\n";
    output += "\n";
    output += "A game of Minesweeper begins when the player first selects a cell on a board. The first click is guaranteed to be safe, whilst some variants further guarantee that all adjacent cells are safe as well. During the game, the player uses information given from the opened cells to deduce further cells that are safe to open, iteratively gaining more information to solve the board.\n";
    output += "\n";
    output += "To win a game of Minesweeper, all non-mine cells must be opened without opening a mine. There are 10 mines on this 8x10 board.\n";
    output += "\n";
    output += "Press any key to return to main menu.\n\n";

    for (char c : output) {
        cout << c << flush;
        usleep(5000);
    }

    string input;
    cin >> input;
    return "return";
}

void Game::executeGame() {
    system("clear");

    int row = -1;
    int column = -1;
    
    printGrid(false);
    cout << "Enter the row of your first choice: ";
    cin >> row;
    cout << "\n";
    while(cin.fail() or row < 0 or row > 7) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        cout << "Please enter a valid row: ";
        cin >> row;
        cout << "\n";
    }
    cout << "Enter the column of your first choice: ";
    cin >> column;
    cout << "\n";
    while(cin.fail() or column < 0 or column > 9) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        cout << "Please enter a valid column: ";
        cin >> column;
        cout << "\n";
    }
    generateGrid(row, column);
    revealChoice(row, column);
    system("clear");
    printGrid(false);

    while(!gameOver) {
        row = -1;
        column = -1;
        while(!validIndex(row, column)) {
            cout << "Enter your next row: ";
            cin >> row;
            cout << "\n";
            while(cin.fail() or row < 0 or row > 7) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                cout << "Please enter a valid row: ";
                cin >> row;
                cout << "\n";
            }
            cout << "Enter your next column: ";
            cin >> column;
            cout << "\n";
            while(cin.fail() or column < 0 or column > 9) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                cout << "Please enter a valid column: ";
                cin >> column;
                cout << "\n";
            }
        }
        system("clear");
        if(grid[row][column] == -1) {
            gameOver = true;
        }
        else {
            revealChoice(row, column);
            if(uncoveredSquares >= 70) {
                gameOver = true;
            }
            else {
                printGrid(false);
            }
        }
    }
}

void Game::generateGrid(int userRow, int userColumn) {
    int index;
    int mineRow;
    int mineColumn;
    srand(time(0));
    for(int i = 0; i < 10; ++i) {
        do {
            index = rand() % 80;
            mineRow = index / 10;
            mineColumn = index % 10;
        }
        while(!validMineIndex(userRow, userColumn, mineRow, mineColumn));

        grid[mineRow][mineColumn] = -1;

        if(validIndex(mineRow - 1, mineColumn - 1) and (grid[mineRow - 1][mineColumn - 1] != -1)) {
            grid[mineRow - 1][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow - 1, mineColumn) and (grid[mineRow - 1][mineColumn] != -1)) {
            grid[mineRow - 1][mineColumn] += 1;
        }
        if(validIndex(mineRow - 1, mineColumn + 1) and (grid[mineRow - 1][mineColumn + 1] != -1)) {
            grid[mineRow - 1][mineColumn + 1] += 1;
        }
        if(validIndex(mineRow, mineColumn - 1) and (grid[mineRow][mineColumn - 1] != -1)) {
            grid[mineRow][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow, mineColumn + 1) and (grid[mineRow][mineColumn + 1] != -1)) {
            grid[mineRow][mineColumn + 1] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn - 1) and (grid[mineRow + 1][mineColumn - 1] != -1)) {
            grid[mineRow + 1][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn) and (grid[mineRow + 1][mineColumn] != -1)) {
            grid[mineRow + 1][mineColumn] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn + 1) and (grid[mineRow + 1][mineColumn + 1] != -1)) {
            grid[mineRow + 1][mineColumn + 1] += 1;
        }
    }
}

bool Game::validMineIndex(int userRow, int userColumn, int mineRow, int mineColumn) {
    if(grid[mineRow][mineColumn] == -1) {
        return false;
    }
    else if((userRow == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn - 1) and (userRow - 1 == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn) and (userRow - 1 == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn + 1) and (userRow - 1 == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow, userColumn - 1) and (userRow == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow, userColumn + 1) and (userRow == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn - 1) and (userRow + 1 == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn) and (userRow + 1 == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn + 1) and (userRow + 1 == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else {
        return true;
    }
}

bool Game::validIndex(int row, int column) {
    if(((row >= 0) and (row < 8)) and ((column >= 0) and (column < 10))) {
        return true;
    }
    else {
        return false;
    }
}

void Game::revealChoice(int row, int column) {
    if(validIndex(row, column)) {
        if(gridToPrint[row][column] == 0) {
            gridToPrint[row][column] = 1;
            uncoveredSquares++;
            if(grid[row][column] == 0){
                revealChoice(row - 1, column - 1);
                revealChoice(row - 1, column);
                revealChoice(row - 1, column + 1);
                revealChoice(row, column - 1);
                revealChoice(row, column + 1);
                revealChoice(row + 1, column - 1);
                revealChoice(row + 1, column);
                revealChoice(row + 1, column + 1);
            }
        }
    }
}

void Game::printGrid(bool endGame) {
    cout << "             █▀▀█  █   ▄█─   █   █▀█   █   █▀▀█  █  ─█▀█─  █   █▀▀   █   ▄▀▀▄  █   ▀▀▀█  █   ▄▀▀▄  █   ▄▀▀▄  \n";
    cout << "             █▄▀█  █   ─█─   █   ─▄▀   █     ▀▄  █  █▄▄█▄  █   ▀▀▄   █   █▄▄─  █   ──█─  █   ▄▀▀▄  █   ▀▄▄█  \n";
    cout << "             █▄▄█  █   ▄█▄   █   █▄▄   █   █▄▄█  █  ───█─  █   ▄▄▀   █   ▀▄▄▀  █   ─▐▌─  █   ▀▄▄▀  █   ─▄▄▀  \n";
    cout << "        ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";

    string output1 = "";
    string output2 = "";
    string output3 = "";

    for(int i = 0; i < 8; ++i) {
        cout << "        █  \n";
        printNumbers(i, output1, output2, output3, false);
        output1 += " █  ";
        output2 += " █  ";
        output3 += " █  ";
        for(int j = 0; j < 10; ++j) {
            if(endGame or gridToPrint[i][j] != 0) {
                if(grid[i][j] == -1) {
                    printNumbers(-1, output1, output2, output3, true);
                }
                else {
                    printNumbers(grid[i][j], output1, output2, output3, true);
                }
            }
            else {
                output1 += " ▄▄▄▄▄ ";
                output2 += " █   █ ";
                output3 += " ▀▀▀▀▀ ";
            }
            output1 += "   ";
            output2 += "   ";
            output3 += "   ";
        }
        cout << output1 << "\n";
        cout << output2 << "\n";
        cout << output3 << "\n";
        output1 = "";
        output2 = "";
        output3 = "";
    }
    cout << "\n";
}

void Game::printNumbers(int num, string& output1, string& output2, string& output3, bool inGrid) {
    if(num == -1) {
        output1 += "\033[1;31m   ,   \033[0m";
        output2 += "\033[1;31m  <><  \033[0m";
        output3 += "\033[1;31m   `   \033[0m";
    }
    else if(num == 0) {
        if(inGrid) {
            output1 += "\033[1;32m  █▀▀█ \033[0m";
            output2 += "\033[1;32m  █▄▀█ \033[0m";
            output3 += "\033[1;32m  █▄▄█ \033[0m";
        }
        else {
            output1 += "  █▀▀█ ";
            output2 += "  █▄▀█ ";
            output3 += "  █▄▄█ ";
        }
    }
    else if(num == 1) {
        if(inGrid) {
            output1 += "\033[1;32m  ▄█─  \033[0m";
            output2 += "\033[1;32m  ─█─  \033[0m";
            output3 += "\033[1;32m  ▄█▄  \033[0m";
        }
        else {
            output1 += "  ▄█─  ";
            output2 += "  ─█─  ";
            output3 += "  ▄█▄  ";
        }
    }
    else if(num == 2) {
        if(inGrid) {
            output1 += "\033[1;32m  █▀█  \033[0m";
            output2 += "\033[1;32m  ─▄▀  \033[0m";
            output3 += "\033[1;32m  █▄▄  \033[0m";
        }
        else {
            output1 += "  █▀█  ";
            output2 += "  ─▄▀  ";
            output3 += "  █▄▄  ";
        }
    }
    else if(num == 3) {
        if(inGrid) {
            output1 += "\033[1;32m  █▀▀█ \033[0m";
            output2 += "\033[1;32m    ▀▄ \033[0m";
            output3 += "\033[1;32m  █▄▄█ \033[0m";
        }
        else {
            output1 += "  █▀▀█ ";
            output2 += "    ▀▄ ";
            output3 += "  █▄▄█ ";
        }
    }
    else if(num == 4) {
        if(inGrid) {
            output1 += "\033[1;32m ─█▀█─ \033[0m";
            output2 += "\033[1;32m █▄▄█▄ \033[0m";
            output3 += "\033[1;32m ───█─ \033[0m";
        }
        else {
            output1 += " ─█▀█─ ";
            output2 += " █▄▄█▄ ";
            output3 += " ───█─ ";
        }
    }
    else if(num == 5) {
        if(inGrid) {
            output1 += "\033[1;32m  █▀▀  \033[0m";
            output2 += "\033[1;32m  ▀▀▄  \033[0m";
            output3 += "\033[1;32m  ▄▄▀  \033[0m";
        }
        else {
            output1 += "  █▀▀  ";
            output2 += "  ▀▀▄  ";
            output3 += "  ▄▄▀  ";
        }
    }
    else if(num == 6) {
        if(inGrid) {
            output1 += "\033[1;32m  ▄▀▀▄ \033[0m";
            output2 += "\033[1;32m  █▄▄─ \033[0m";
            output3 += "\033[1;32m  ▀▄▄▀ \033[0m";
        }
        else {
            output1 += "  ▄▀▀▄ ";
            output2 += "  █▄▄─ ";
            output3 += "  ▀▄▄▀ ";
        }
    }
    else if(num == 7) {
        if(inGrid) {
            output1 += "\033[1;32m  ▀▀▀█ \033[0m";
            output2 += "\033[1;32m  ──█─ \033[0m";
            output3 += "\033[1;32m  ─▐▌─ \033[0m";
        }
        else {
            output1 += "  ▀▀▀█ ";
            output2 += "  ──█─ ";
            output3 += "  ─▐▌─ ";
        }
    }
    else if(num == 8) {
        if(inGrid) {
            output1 += "\033[1;32m  ▄▀▀▄ \033[0m";
            output2 += "\033[1;32m  ▄▀▀▄ \033[0m";
            output3 += "\033[1;32m  ▀▄▄▀ \033[0m";
        }
        else {
            output1 += "  ▄▀▀▄ ";
            output2 += "  ▄▀▀▄ ";
            output3 += "  ▀▄▄▀ ";
        }
    }
    else if(num == 9) {
        if(inGrid) {
            output1 += "\033[1;32m  ▄▀▀▄ \033[0m";
            output2 += "\033[1;32m  ▀▄▄█ \033[0m";
            output3 += "\033[1;32m  ─▄▄▀ \033[0m";
        }
        else {
            output1 += "  ▄▀▀▄ ";
            output2 += "  ▀▄▄█ ";
            output3 += "  ─▄▄▀ ";
        }
    }
}
