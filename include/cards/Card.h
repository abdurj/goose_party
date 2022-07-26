#ifndef CARD_H
#define CARD_H
#include <memory>
#include <string>
class Player;
class Board;
class Card {
    public:
    virtual void apply(Player*, std::shared_ptr<Player>, Board*) = 0;
    virtual bool requiresTarget() = 0;
    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;
    virtual ~Card();
};





#endif
