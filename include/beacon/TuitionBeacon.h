#ifndef TUITIONBEACON_H
#define TUITIONBEACON_H

#include "beacon/Beacon.h"

class Player;

class TuitionBeacon : public Beacon {
    void doEffect(std::vector<std::shared_ptr<Player>>&, Board&) override;
    void doActivate(const std::shared_ptr<Player>&) override;
    std::string getDesc() const override;
    public:
    PeriodType period() const override;
    TuitionBeacon();
};

#endif
