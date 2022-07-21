#include <cstdlib>
#include "utils/Utils.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

namespace utils {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    // TODO: Use C++ style random
    int roll(std::shared_ptr<Player> p) {
        srand(seed);
        int roll = rand() % 12;
        cout << "Rolled a: " << roll << endl;
        return roll;
    }

    void shufflePlayers(vector<shared_ptr<Player>> &players) {
        // randomize order of the players. 
        shuffle (players.begin(), players.end(), default_random_engine(seed));
    }

}
