#ifndef GOOSE_PARTY_UTILS_H
#define GOOSE_PARTY_UTILS_H

#include <memory>
#include <utility>
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

    int roll(int c = 0);
    int roll2(int c = 0);

    /**
     * @brief Generates a random number
     *
     * @param u upper bound inclusive
     * @param l lower bound inclusive, default 0
     * @return random number
     */
    int rng(int u, int l = 0);

    void shufflePlayers(std::vector<std::shared_ptr<Player>>&);

    std::unique_ptr<Card> generateCard();

    std::shared_ptr<Tile> baseCell(int t = 0);

    std::shared_ptr<Tile> degreeTile(int t = 0);

    std::shared_ptr<Tile> gradeTile(int t = 0);

    std::shared_ptr<Tile> cardTile(int t = 0);

    std::shared_ptr<Tile> healthTile(int t = 0);

    std::shared_ptr<Tile> abilityTile(int t = 0);

    std::shared_ptr<Tile> beaconTile(int t = 0);

    void generateAbility(std::shared_ptr<Player> &);
}

#endif //GOOSE_PARTY_UTILS_H
