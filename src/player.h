#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <windows.h>

class Player {
private:
    std::string name;
    float totalWinnings;
public:
    Player(std::string playerName);
    void addWinnings(float amount);
    float getTotalWinnings();
};

#endif
