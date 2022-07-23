#include "utils/Utils.h"

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <random>

#include "cards/SpellCard.h"
#include "cards/TrapCard.h"
#include "cards/Card.h"

#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"
#include "tiles/DegreeTile.h"
#include "tiles/GradeTile.h"
#include "tiles/AbilityTile.h"
#include "tiles/BeaconTile.h"
#include "tiles/HealthTile.h"
#include "tiles/CardTile.h"


using namespace std;

namespace utils {

    int roll(std::shared_ptr<Player> p, int c) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine eng(seed);
        int roll = (eng() + c - 12) % c;
        cout << "Rolled a: " << roll << endl;
        return roll;
    }

    void shufflePlayers(vector<shared_ptr<Player>> &players) {
        // randomize order of the players. 
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle (players.begin(), players.end(), default_random_engine(seed));
    }

    unique_ptr<Card> generateCard() {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine eng(seed);
        int rand = (eng()) % 10;
        switch (rand) {
            case 0: {
                return make_unique<JuiceCard>();
            }
            case 1: {
                break;
            }
            default: {
                return make_unique<JuiceCard>();
            }
        }
        return make_unique<JuiceCard>();
    }

    shared_ptr<Tile> baseCell(bool inter) {
        return make_shared<BaseTile>(inter);
    }

    shared_ptr<Tile> degreeTile(bool inter) {
        return make_shared<DegreeTile>(inter);
    }

    shared_ptr<Tile> gradeTile(bool inter) {
        return make_shared<GradeTile>(inter);
    }

    shared_ptr<Tile> cardTile(bool inter) {
        return make_shared<CardTile>(inter);
    }

    shared_ptr<Tile> healthTile(bool inter) {
        return make_shared<HealthTile>(inter);
    }

    shared_ptr<Tile> abilityTile(bool inter) {
        return make_shared<AbilityTile>(inter);
    }

    shared_ptr<Tile> beaconTile(bool inter) {
        return make_shared<BeaconTile>(inter);
    }
}
