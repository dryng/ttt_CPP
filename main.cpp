#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "Player.h" // problem including multiple header files?? what the fuck lol

using namespace std;

int main() {

    Player p1 {"Danny", "X"};
    Player p2 {"Bob", "0"};
    Board board {3, 0, p1, p2};
    board.print();

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


        board.makeMove(x, y, curPlayer);
        board.print();

        if (curPlayerFlip == 1)
            curPlayerFlip = 2;
        else
            curPlayerFlip = 1;

        //curPlayerFlip = 1 ? curPlayerFlip == 2 : 2;
    }
    return 0;
}
