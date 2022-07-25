#include "beacon/ExamBeacon.h"
#include <iostream>
#include <cstdlib>
#include "player/Player.h"
using namespace std;

ExamBeacon::ExamBeacon() {}

PeriodType ExamBeacon::period() const {return PeriodType::Cycle;}

void ExamBeacon::doActivate(shared_ptr<Player>& p) {
    duration = 2;
    cout << "Exam Beacon has been activated by " << p->Options()->name << ". ";
    
}

void ExamBeacon::doEffect(vector<shared_ptr<Player>> &players, Board &board) {
    for(auto &p : players) {
        if(p != activator) {
            p->modifyHP(-2);
        }
    }
}

string ExamBeacon::getDesc() const {
    return "Exam Beacon - At the end of every cycle for 2 cycles, every player except the activator takes 2 damage.";
}