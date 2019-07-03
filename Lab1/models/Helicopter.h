#ifndef LAB1_HELICOPTER_H
#define LAB1_HELICOPTER_H


#include <string>
#include <ostream>

using namespace std;

class Helicopter {
private:
    int passengersNumber;
    string name;
    int maxSpeed;
public:
    Helicopter(int passengersNumber = 0, const string &name = "", int maxSpeed = 0);

    int getPassengersNumber() const;

    void setPassengersNumber(int passengersNumber);

    const string &getName() const;

    void setName(const string &name);

    int getMaxSpeed() const;

    void setMaxSpeed(int maxSpeed);

    friend ostream &operator<<(ostream &os, const Helicopter &helicopter);
};


#endif //LAB1_HELICOPTER_H
