#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
using std::string;

class Player {
private:
    string name;
    string icon; // i.e "x" or "o"
public:
    Player(string name, string icon);
    string getName();
    string getIcon();
    void setName(string name);
    void setIcon(string icon);
};

#endif