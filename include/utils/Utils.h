#ifndef GOOSE_PARTY_UTILS_H
#define GOOSE_PARTY_UTILS_H

#include <memory>
#include <utility>
#include <unordered_set>
#include <vector>
#include "player/Player.h"
#include "tiles/Tile.h"
#include <string>
#include "cards/Card.h"


namespace utils {

    /**
     * @brief Makes a dice roll for a given player @param p
     *
     * @param p the Player class
     * @return int The dice roll the player got
     */

    namespace {
        static std::unordered_set<std::string> playerAbilities;
    }

    int roll(int c = 0);

    void shufflePlayers(std::vector<std::shared_ptr<Player>>&);

    std::unique_ptr<Card> generateCard();

    std::shared_ptr<Tile> baseCell(bool inter = false);

    std::shared_ptr<Tile> degreeTile(bool inter = false);

    std::shared_ptr<Tile> gradeTile(bool inter = false);

    std::shared_ptr<Tile> cardTile(bool inter = false);

    std::shared_ptr<Tile> healthTile(bool inter = false);

    std::shared_ptr<Tile> abilityTile(bool inter = false);

    std::shared_ptr<Tile> beaconTile(bool inter = false);

    void drawAbility(std::shared_ptr<Player> &);
}

#endif //GOOSE_PARTY_UTILS_H
