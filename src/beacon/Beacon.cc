#include "beacon/Beacon.h"
#include "player/Player.h"
#include <iostream>

using namespace std;

Beacon::Beacon() : duration{0}, activator{nullptr} {}

int Beacon::Duration() const {return duration;}

void Beacon::decrementDuration() {
    duration = max(0, duration-1);
    if(duration == 0) {activator = nullptr;}
}

void Beacon::activate(shared_ptr<Player> &p) {
    activator = p;
    doActivate(p);
    string periodStr = (period() == PeriodType::Cycle) ? "cycles" : "turns";
    cout << "This beacon will last " << duration << " " << periodStr << ".";
}

void Beacon::effect(vector<shared_ptr<Player>> &players, Board &board) {
    doEffect(players, board);
}

void Beacon::Desc() const {
    cout << getDesc() << endl;
    if(activator) {
        cout << "Activated By: " << activator->Options()->name << endl;
    }
    if(duration > 0) {
        cout << "Duration: " << duration << endl;
    }
}