#include <cstdlib>
#include "utils/Utils.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

namespace utils {

    // TODO: Use C++ style random
    int roll(std::shared_ptr<Player> p) {
        int roll = rand() % 12;
        cout << "Rolled a: " << roll << endl;
        return roll;
    }

}
