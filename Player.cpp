#include <string>
#include "Player.h"
using std::string;

// "this->" throws an error
Player::Player(string playerName, string playerIcon)
    :name {playerName}, icon {playerIcon} {
}

string Player::getName() {
    return name;
}

string Player::getIcon() {
    return icon;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setIcon(string icon) {
    this->icon = icon;
}