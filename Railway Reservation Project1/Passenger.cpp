#include "Passenger.h"

int Passenger::id = 1;

Passenger::Passenger()
:name(""),age(0),gender(' '),berthPreference(' '),cName(""),cage(0)
{

}

Passenger::Passenger(std::string name, int age, char gender, char berthPreference, std::string cName, int cage)
{
    this->PassengerId = id++;

    this->name = name;
    this->age = age;
    this->gender = gender;
    this->berthPreference = berthPreference;

    this->cName = cName;
    this->cage = cage;

    this->number = -1;
    this->alloted = "";
}
