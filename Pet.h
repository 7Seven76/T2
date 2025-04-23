//
// Created by Ryank on 2/25/2025.
//

#ifndef PET_H
#define PET_H
#include <string>
#include "IntrestedAdopter.h"

using namespace std;

class Pet {
public:
    Pet();
    Pet(string name, int ID, int days_in_shelter, string color, string Animal_Type);

    string getName() const;
    int getID() const;
    int getDays_in_shelter() const;
    string getColor() const;
    string getAnimal_Type() const;

    virtual void getInfo();
    void incrementDaysInShelter();

    void setName(string name);
    void setID(int ID);
    void setDays_in_shelter(int days);
    void setColor(string color);
    void setAnimal_Type(string Animal_Type);

    void setAdopter(InterestedAdopter* adopter);
    void clearAdopter();

private:
    string name;
    int ID;
    int days_in_shelter;
    string color;
    string Animal_Type;
    InterestedAdopter* adopter;
};

#endif //PET_H