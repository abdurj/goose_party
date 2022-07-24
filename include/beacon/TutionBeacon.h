#ifndef TUITIONBEACON_H
#define TUITIONBEACON_H

#include "beacon/Beacon.h"

class Player;

class TutionBeacon : public Beacon {
    void doEffect(std::vector<std::shared_ptr<Player>>&, Board&) override;
    void doActivate(std::shared_ptr<Player>&) override;
    std::string getDesc() const override;
    public:
    PeriodType period() const override;
    TutionBeacon();
};

#endif
