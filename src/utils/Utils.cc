#include "utils/Utils.h"

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <unordered_set>

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


#include "player/Player.h"
#include "player/ability/GradeCurve.h"
#include "player/ability/AllNighter.h"
#include "player/ability/GoodSleep.h"
#include "player/ability/TimeManagement.h"
#include "player/ability/BonusMarks.h"
#include "player/ability/Attendance.h"
#include "player/ability/PerfectGpa.h"

using namespace std;

namespace utils {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine eng(seed);

    int roll(int c) {
        int roll = (eng() % 12) + c;
        cout << "Rolled a: " << roll << endl;
        return roll;
    }

    void shufflePlayers(vector<shared_ptr<Player>> &players) {
        // randomize order of the players. 
        shuffle (players.begin(), players.end(), eng);
    }

    unique_ptr<Card> generateCard() {
        // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
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

    void generateAbiltiy(shared_ptr<Player> &p) {    
        int abilityCount = 7;
        int n = eng() % (abilityCount+1);
        unordered_set<string> playerAbilities = p->Abilities();
        string ability;

        if(playerAbilities.size() == abilityCount) {
            cout << endl << "This player has every possible ability" << endl << endl;
            return;
        }
        for(int i = 0; i < abilityCount; ++i) {
             switch((n+i) % abilityCount) {
                case 0:
                    ability = "GradeCurve";
                    if(!playerAbilities.count(ability)) {
                        p = make_shared<GradeCurve>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;
                case 1:
                    ability = "AllNighter";
                    if(!playerAbilities.count(ability)) {
                        
                        p = make_shared<AllNighter>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;
                case 2:
                    ability = "BonusMarks";                
                    if(!playerAbilities.count(ability)) {

                        p = make_shared<BonusMarks>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;
                case 3:
                    ability = "GoodSleep";
                    if(!playerAbilities.count(ability)) {
                        p = make_shared<GoodSleep>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;
                case 4:
                    ability = "TimeManagement";
                    if(!playerAbilities.count(ability)) {
                        p = make_shared<TimeManagement>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;
                case 5:
                    ability = "Attendance";
                    if(!playerAbilities.count(ability)) {
                        p = make_shared<Attendance>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << "TimeManagement" << endl;
                        return;
                    }  
                break;
                case 6:
                    ability = "PerfectGpa";
                    if(!playerAbilities.count(ability)) {
                        p = make_shared<PerfectGpa>(p);
                        cout << endl << p->Options()->name << " now has the ability: " << ability << endl << endl;
                        return;
                    }  
                break;                              
                default:
                cout << "Shouldn't be here" << endl;//TODO delete this
            } 
        }
    }
}
