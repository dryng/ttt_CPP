#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <string>
#include "Player.h"

using std::string;

class Board {
private:
    int size;
    int posFilled;
    string player1Icon;
    string player2Icon;
    std::vector<std::vector<string>> grid;

    // return wether the given spot is empty or not
    bool posOpen(int x, int y);
     /*
    ret vals: 
        -1: spot taken
        0: ongoing
        1: player 1 wins
        2: player 2 wins
        3: tie (board is full)
    */
    int boardState();
public:
    Board(int size, int fllled, Player player1Icon, Player player2Icon);
    // true if position added, false is faileds
    int makeMove(int x, int y, Player player);
    void print();
};

#endif