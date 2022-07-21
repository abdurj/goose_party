#ifndef GOOSE_PARTY_UTILS_H
#define GOOSE_PARTY_UTILS_H

#include <memory>
#include "player/Player.h"
#include <algorithm>
#include <chrono>
#include <random>
namespace utils {

    /**
     * @brief Makes a dice roll for a given player
     *
     * @param p the Player class
     * @return int The dice roll the player got
     */
    int roll(std::shared_ptr<Player> p);

    void shufflePlayers(std::vector<std::shared_ptr<Player>>&);

}

#endif //GOOSE_PARTY_UTILS_H
