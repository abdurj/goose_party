#include "utils/Utils.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

namespace utils {

    int roll(std::shared_ptr<Player> p) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine eng(seed);
        int roll = eng() % 12;
        cout << "Rolled a: " << roll << endl;
        return roll;
    }

    void shufflePlayers(vector<shared_ptr<Player>> &players) {
        // randomize order of the players. 
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle (players.begin(), players.end(), default_random_engine(seed));
    }

}
