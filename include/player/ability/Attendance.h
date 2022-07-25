#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include "player/PlayerDecorator.h"

class Attendance : public PlayerDecorator {
    int count;
    void doEndTurn() override;
    void abilityDesc() const override;
    public:
    Attendance(std::shared_ptr<Player>);
};


#endif