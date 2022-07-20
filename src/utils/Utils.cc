#include <cstdlib>
#include "utils/Utils.h"

using namespace std;

namespace utils {

    // TODO: Use C++ style random
    int roll(std::shared_ptr<Player> p) {
        return rand() % 12;
    }

}
