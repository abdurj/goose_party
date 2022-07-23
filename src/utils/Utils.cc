#include "utils/Utils.h"

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <random>


#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"
#include "tiles/DegreeTile.h"
#include "tiles/GradeTile.h"
#include "tiles/AbilityTile.h"
#include "tiles/BeaconTile.h"
#include "tiles/HealthTile.h"
#include "tiles/CardTile.h"


#include "player/Player.h"
#include "ability/GradeCurve.h"
#include "ability/AllNighter.h"
#include "ability/GoodSleep.h"
#include "ability/TimeManagement.h"
#include "ability/BonusMarks.h"

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

    void drawAbility(shared_ptr<Player> &p) { 
        //TODO randomly generate n
        int n = 0;
        int abilityCount = 5; //Hard coded for now, is there a better way to do this?
        string key = "";

        for(int i = 0; i < abilityCount; ++i) {
             switch((n+i) % abilityCount) {
                case 0:
                    key = to_string(p->Options()->id) + "GradeCurve";
                    if(!playerAbilities.count(key)) {
                        p = make_shared<GradeCurve>(p);
                        playerAbilities.insert(key);
                        cout << p->Options()->name << " now has the ability: " << "GradeCurve" << endl;
                        return;
                    }  
                break;
                case 1:
                    key = to_string(p->Options()->id) + "AllNighter";
                    if(!playerAbilities.count(key)) {
                        p = make_shared<AllNighter>(p);
                        playerAbilities.insert(key);
                        cout << p->Options()->name << " now has the ability: " << "AllNighter" << endl;
                        return;
                    }  
                break;
                case 2:
                    key = to_string(p->Options()->id) + "BonusMarks";
                    if(!playerAbilities.count(key)) {
                        p = make_shared<BonusMarks>(p);
                        playerAbilities.insert(key);
                        cout << p->Options()->name << " now has the ability: " << "BonusMarks" << endl;
                        return;
                    }  
                break;
                case 3:
                    key = to_string(p->Options()->id) + "GoodSleep";
                    if(!playerAbilities.count(key)) {
                        p = make_shared<GoodSleep>(p);
                        playerAbilities.insert(key);
                        cout << p->Options()->name << " now has the ability: " << "GoodSleep" << endl;
                        return;
                    }  
                break;
                case 4:
                    key = to_string(p->Options()->id) + "TimeManagement";
                    if(!playerAbilities.count(key)) {
                        p = make_shared<TimeManagement>(p);
                        playerAbilities.insert(key);
                        cout << p->Options()->name << " now has the ability: " << "TimeManagement" << endl;
                        return;
                    }  
                break;
                default:
                cout << "Shouldn't be here" << endl;
            } 
        }
        cout << "already has" << endl;
    }
}
