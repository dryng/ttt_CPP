#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "Player.h"

using namespace std;

void play(Board &board, Player &p1, Player &p2) {

    int moveRes {0};
    int curPlayerFlip {1};
    Player curPlayer {p1}; // make pointer? 
    bool ongoing {true};

    while (ongoing) {
        if (curPlayerFlip == 1)
            curPlayer = p1;
        else
            curPlayer = p2;
        //curPlayer = p1 ? curPlayerFlip == 1 : p2; "expression must have bool type ? "
        int x {};
        int y {};
        cout << curPlayer.getName() + " enter x: " << endl;
        cin >> x;
        cout << curPlayer.getName() + " enter y: " << endl;
        cin >> y;

        moveRes = board.makeMove(x, y, curPlayer);
        board.print();

        if (moveRes == -1)
            cout << "Sorry " + curPlayer.getName() + " that spot is taken " << endl;
        else if (moveRes == 1)
            cout << p1.getName() + "you win!" << endl;
        else if (moveRes == 2)
            cout << p2.getName() + " you win!" << endl;
        else if (moveRes == 3)
            cout << "It's a tie!" << endl;

        if (curPlayerFlip == 1)
            curPlayerFlip = 2;
        else
            curPlayerFlip = 1;

        //curPlayerFlip = 1 ? curPlayerFlip == 2 : 2;
    }

}

int main() {
    Player p1 {"Danny", "X"};
    Player p2 {"Bob", "0"};
    Board board {3, 0, p1, p2};

    play(board, p1, p2);
    return 0;
}
