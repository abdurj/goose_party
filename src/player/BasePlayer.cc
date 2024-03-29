#include "player/BasePlayer.h"
#include <iostream>
#include <string>
#include <utility>

using namespace ftxui;
using namespace std;

BasePlayer::BasePlayer(shared_ptr<PlayerOptions> p): degrees{0}, grades{0}, options{std::move(p)} {
}

//Getters
shared_ptr<PlayerOptions> BasePlayer::Options() const {
    return options;
}

int BasePlayer::Grades() const {return grades;}
int BasePlayer::Degrees() const {return degrees;}

//Setters
int BasePlayer::modifyGrades(int amt) { //Returns int because we can re-use this for "stealing" grades
    int tmp = grades;
    grades = max(0, grades + amt);
    return min(abs(amt), tmp);
}

bool BasePlayer::claimDegree() { //Returns true if a degree was claimed
    if(grades >= 30) {
        grades = max(0, grades - 30);
        cout << "degree claimed" << endl;
        degrees++;

        if(degrees >= 3) {
            cout << "W player" << endl;
        }
        
        return true;
    }

    return false;
}

void BasePlayer::addCard(unique_ptr<Card> p) {
    deck.emplace_back(move(p));
}

void BasePlayer::addAbility(string s) {
    abilities.insert(s);
}

const unordered_set<std::string>& BasePlayer::Abilities() const {return abilities;}

void BasePlayer::doEndTurn(vector<shared_ptr<Player>>&) {}
void BasePlayer::doEndCycle(vector<shared_ptr<Player>>&) {}


void BasePlayer::abilityDesc() const {
    cout << options->name << "\'s abilities: " << endl;
}

int BasePlayer::listCards() const {
    cout << "Available Cards: ";
    for (int i = 0; i < deck.size(); ++i) {
        cout << deck[i]->getName() << ", ";
    }
    cout << endl;
    return deck.size();
}

void BasePlayer::cardDescriptions() const {
    cout << "Available Cards and their descriptions:" << endl;
    for (int i = 0; i < deck.size(); ++i) {
        cout << deck[i]->getName() << ": " << deck[i]->getDescription() << endl;
    }
}

void BasePlayer::useCard(int i, shared_ptr<Player> p, Board* b) {
    deck.at(i)->apply(this, p, b);
    deck.erase(next(deck.begin(), i));
}   

bool BasePlayer::requiresTarget(int i) {
    return deck.at(i)->requiresTarget();
}

int BasePlayer::getHP() const{
    return max(0, hp);
}

bool BasePlayer::alive() const {
    return hp > 0;
}

void BasePlayer::modifyHP(int amt) {
    if(amt <= 0){
        cout << options->name << " has taken " << -amt << " damage!" << endl;
    }else{
        cout << options->name << " has healed for " << min(20-hp, amt) << " HP!" << endl;
    }

    hp = min(hp+amt, 20);
    if(hp <= 0){
        int grades_lost = grades * 0.15;
        cout << options->name << " has died and lost " << grades_lost << " grades!" << endl;
        modifyGrades(-grades_lost);
    }else{
        cout << options->name << " has " << hp << " hp" << endl;
    }
}

void BasePlayer::reset() {
    hp = 20;
}

void BasePlayer::info() const {
    cout << "Name: " << options->name << endl;
    cout << "ID: " << options->id << endl;
    cout << "HP: " << getHP()  << endl;
    cout << "Attack: " << options->attack << endl;
    cout << "Defence: " << options->defence << endl;
    cout << "Luck: " << options->luck << endl;
    cout << "Grades: " << Grades() << endl;
    cout << "Degrees: " << Degrees() << endl;
}

int BasePlayer::getRolls() const {
    return 2;
}