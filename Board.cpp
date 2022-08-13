#include "Board.h"
#include "Player.h"
//#include "math.h" // math (abs) ??
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

//"this->" not working with constructor
//make posFilled default to 0
Board::Board(int boardSize, int filled, Player player1, Player player2)
    : size{boardSize}, posFilled{filled}, player1Icon{player1.getIcon()}, player2Icon{player2.getIcon()} {
    // how to init 2d vector? 
    for (int i = 0; i < size; i++) {
        grid.push_back(vector<string> (size, " "));
    }
}

bool Board::posOpen(int x, int y) {
    return grid.at(x).at(y) == " ";
}

/*
    ret vals: 
        -1: spot taken
        0: ongoing
        1: player 1 wins
        2: player 2 wins
        3: tie (board is full)
*/
int Board::makeMove(int x, int y, Player player) {
    if (!posOpen(x, y)) {
        return -1;
    }
    grid.at(x).at(y) = player.getIcon();
    // check state
    //cout << "Board State: " << boardState() << endl;
    return boardState();
}

/*
    ret vals: 
        0: ongoing
        1: player 1 wins
        2: player 2 wins
        3: tie (board is full)
*/
int Board::boardState() {
    vector<int> rows (size, 0);
    vector<int> cols (size, 0);
    int diag {0};
    int antiDiag {0};

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            string curVal = grid.at(r).at(c);
            if (curVal != " ") {
                int toAdd = 0;
                if (curVal == player1Icon)
                    toAdd = 1;
                else if (curVal == player2Icon)
                    toAdd = -1;
                rows.at(r) += toAdd;
                cols.at(c) += toAdd;
                if (r == c)
                    diag += toAdd;
                if (r + c == size - 1)
                    antiDiag += toAdd;

                if (rows.at(r) == size || (rows.at(r) * -1) == size
                    || cols.at(r) == size || (cols.at(r) * -1) == size
                    || diag == size || (diag * -1) == size
                    || antiDiag == size || (antiDiag * -1) == size)
                    return 1 ? toAdd == 1 : 2;
            }
        }
    }
    return 0 ? posFilled < size : 3;
}

/*   
    prob dont wanna actually print from here 
    return a representation of board and have main print it

    Ex: 
        |   |   
    -----------
        | X |
    --------------
      X |   |  O
*/  
void Board::print() {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (c < size - 1)
                cout << " " + grid.at(r).at(c) + " |";
            else
                cout << " " + grid.at(r).at(c) + " ";
        }
        if (r < size - 1)
            cout << "\n-----------" << endl;
        else
            cout << endl;
    }
    cout << endl;
}