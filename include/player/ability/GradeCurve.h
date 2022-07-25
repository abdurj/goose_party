#ifndef GRADECURVE_H
#define GRADECURVE_H

#include "player/PlayerDecorator.h"

class GradeCurve : public PlayerDecorator {
    void doEndCycle() override;
    void abilityDesc() const override;
    public:
    GradeCurve(std::shared_ptr<Player>);
};


#endif