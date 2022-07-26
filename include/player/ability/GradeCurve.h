#ifndef GRADECURVE_H
#define GRADECURVE_H

#include "player/PlayerDecorator.h"

class GradeCurve : public PlayerDecorator {
    void doEndCycle(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    public:
    GradeCurve(std::shared_ptr<Player>);
};


#endif