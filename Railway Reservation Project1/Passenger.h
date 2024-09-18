#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include <string>

class Passenger
{
public:
    static int id;
    int PassengerId;

    std::string name;
    int age;
    char gender;
    char berthPreference;

    std::string cName;
    int cage;

    int number;
    std::string alloted;
    Passenger();
    Passenger(std::string name, int age, char gender, char berthPreference, std::string cName, int cage);
};

#endif // PASSENGER_H_INCLUDED
