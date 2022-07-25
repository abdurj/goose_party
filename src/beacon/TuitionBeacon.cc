#include "beacon/TuitionBeacon.h"
#include <iostream>
#include <cstdlib>
#include "player/Player.h"
using namespace std;

TuitionBeacon::TuitionBeacon() {}

PeriodType TuitionBeacon::period() const {return PeriodType::Cycle;}

void TuitionBeacon::doActivate(shared_ptr<Player>& p) {
    duration = 5; //5 cycles
    cout << "Tuition Beacon has been activated by " << p->Options()->name << ". ";
    
}

void TuitionBeacon::doEffect(vector<shared_ptr<Player>> &players, Board &board) {
    for(auto &p : players) {
        if(p != activator) {
            activator->modifyGrades(abs(p->modifyGrades(-5)));
        }
    }
}

string TuitionBeacon::getDesc() const {
    return "Tuition Beacon - At the end of every cycle for 5 cycles, the player who activated this beacon steals 3 grades from every other player.";
}