#ifndef GOOSE_PARTY_UTILS_H
#define GOOSE_PARTY_UTILS_H

#include <memory>
#include "player/Player.h"
#include "tiles/Tile.h"

namespace utils {

    /**
     * @brief Makes a dice roll for a given player @param p
     *
     * @param p the Player class
     * @return int The dice roll the player got
     */
    int roll(std::shared_ptr<Player> p, int c = 12);

    void shufflePlayers(std::vector<std::shared_ptr<Player>>&);

    std::shared_ptr<Tile> baseCell(bool inter = false);

    std::shared_ptr<Tile> degreeTile(bool inter = false);

    std::shared_ptr<Tile> gradeTile(bool inter = false);

    std::shared_ptr<Tile> cardTile(bool inter = false);

    std::shared_ptr<Tile> healthTile(bool inter = false);

    std::shared_ptr<Tile> abilityTile(bool inter = false);

    std::shared_ptr<Tile> beaconTile(bool inter = false);
}

#endif //GOOSE_PARTY_UTILS_H
