#include "Helicopter.h"

Helicopter::Helicopter(int passengersNumber, const string &name, int maxSpeed) : passengersNumber(passengersNumber),
                                                                                 name(name), maxSpeed(maxSpeed) {}

int Helicopter::getPassengersNumber() const {
    return passengersNumber;
}

void Helicopter::setPassengersNumber(int passengersNumber) {
    Helicopter::passengersNumber = passengersNumber;
}

const string &Helicopter::getName() const {
    return name;
}

void Helicopter::setName(const string &name) {
    Helicopter::name = name;
}

int Helicopter::getMaxSpeed() const {
    return maxSpeed;
}

void Helicopter::setMaxSpeed(int maxSpeed) {
    Helicopter::maxSpeed = maxSpeed;
}

ostream &operator<<(ostream &os, const Helicopter &helicopter) {
    os << "passengersNumber: " << helicopter.passengersNumber << ", name: '" << helicopter.name << "', maxSpeed: "
       << helicopter.maxSpeed;
    return os;
}
