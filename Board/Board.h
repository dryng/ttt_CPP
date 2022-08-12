#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <string>
using std::string;

class Board {
private:
    int size;
    string player1;
    string player2;
    std::vector<std::vector<string>> grid;
public:
    Board(int size, string player1, string player2);
    // return wether the given spot is empty or not
    bool posOpen(int x, int y);
    // true if position added, false is failed
    bool makeMove(int x, int y);
    /*
    ret vals: 
        0: ongoing
        1: player 1 wins
        2: player 2 wins
        -1: tie (board is full)
    */
    int boardState();
    void print();
};

#endif