#ifndef BEACON_H
#define BEACON_H

#include <memory>
#include <vector>
#include <string>

enum class PeriodType { Turn, Cycle };

class Player;
class Board;

class Beacon {
    virtual void doEffect(std::vector<std::shared_ptr<Player>>&, Board &) = 0;
    virtual void doActivate(const std::shared_ptr<Player>&) = 0;
    virtual std::string getDesc() const = 0;
  protected:
    int duration;
    std::shared_ptr<Player> activator;
  public:
    void effect(std::vector<std::shared_ptr<Player>>&, Board &);
    virtual PeriodType period() const = 0;
    void decrementDuration();
    void activate(const std::shared_ptr<Player>&);
    int Duration() const;
    void Desc() const;
    Beacon();
};

#endif
