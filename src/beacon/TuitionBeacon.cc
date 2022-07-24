#include "beacon/TutionBeacon.h"
#include <iostream>
#include <cstdlib>
#include "player/Player.h"
using namespace std;

TutionBeacon::TutionBeacon() {}

PeriodType TutionBeacon::period() const {return PeriodType::Cycle;}

void TutionBeacon::doActivate(shared_ptr<Player>& p) {
    cout << "Tuition Beacon has been activated by " << p->Options()->name << "." << endl;
    duration = 5; //5 cycles
}

void TutionBeacon::doEffect(vector<shared_ptr<Player>> &players, Board &board) {
    for(auto &p : players) {
        if(p != activator) {
            activator->modifyGrades(abs(p->modifyGrades(-5)));
        }
    }
}

string TutionBeacon::getDesc() const {
    return "Tuition Beacon - At the end of every cycle for 5 cycles, the player who activated this beacon steals 3 grades from every other player.";
}