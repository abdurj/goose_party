#ifndef EXAMBEACON_H
#define EXAMBEACON_H

#include "beacon/Beacon.h"

class Player;

class ExamBeacon : public Beacon {
    void doEffect(std::vector<std::shared_ptr<Player>>&, Board&) override;
    void doActivate(std::shared_ptr<Player>&) override;
    std::string getDesc() const override;
    public:
    PeriodType period() const override;
    ExamBeacon();
};

#endif
