#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include "player/PlayerDecorator.h"

class Attendance : public PlayerDecorator {
    int count;
    void doEndTurn() override;
    void listAbilities(std::unordered_set<std::string>&) const override;
    public:
    Attendance(std::shared_ptr<Player>);
};


#endif