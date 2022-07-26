#include "beacon/ExamBeacon.h"
#include <iostream>
#include <cstdlib>
#include "player/Player.h"
using namespace std;

ExamBeacon::ExamBeacon() {}

PeriodType ExamBeacon::period() const {return PeriodType::Cycle;}

void ExamBeacon::doActivate(shared_ptr<Player>& p) {
    duration = 2;
    cout << "Exam Beacon has been activated by " << p->Options()->name << ". " << endl;
}

void ExamBeacon::doEffect(vector<shared_ptr<Player>> &players, Board &board) {
    cout << "Exam Beacon Action - Everyone except " << activator->Options()->name <<
    " takes 5 damage!" << endl;
    for(auto &p : players) {
        if(p != activator) {
            p->modifyHP(-5);
        }
    }
}

string ExamBeacon::getDesc() const {
    return "Exam Beacon - At the end of every cycle for 2 cycles, every player except the activator takes 5 damage.";
}