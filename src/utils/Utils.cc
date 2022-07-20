//
// Created by Abdur on 2022-07-20.
//

#include <cstdlib>
#include "utils/Utils.h"

using namespace std;

namespace utils {

    int roll(std::shared_ptr<Player> p) {
        return rand() % 12;
    }

}