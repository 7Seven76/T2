#include "Pet.h"
#include <iostream>
using namespace std;

Pet::Pet() {
    this->name = "N/A";
    this->ID = -1;
    this->days_in_shelter = -1;
    this->color = "N/A";
    this->Animal_Type = "N/A";
    this->adopter = nullptr;
}

Pet::Pet(string name, int ID, int days_in_shelter, string color, string Animal_Type) {
    this->name = name;
    this->ID = ID;
    this->days_in_shelter = days_in_shelter;
    this->color = color;
    this->Animal_Type = Animal_Type;
    this->adopter = nullptr;
}

string Pet::getName() const {
    return this->name;
}

int Pet::getID() const {
    return this->ID;
}

int Pet::getDays_in_shelter() const {
    return this->days_in_shelter;
}

string Pet::getColor() const {
    return this->color;
}

string Pet::getAnimal_Type() const {
    return this->Animal_Type;
}

void Pet::setName(string name) {
    this->name = name;
}

void Pet::setID(int ID) {
    this->ID = ID;
}

void Pet::setDays_in_shelter(int days_in_shelter) {
    this->days_in_shelter = days_in_shelter;
}

void Pet::setColor(string color) {
    this->color = color;
}

void Pet::setAnimal_Type(string Animal_Type) {
    this->Animal_Type = Animal_Type;
}

void Pet::incrementDaysInShelter() {
    this->days_in_shelter++;
}

void Pet::setAdopter(InterestedAdopter* adopter) {
    this->adopter = adopter;
}

void Pet::clearAdopter() {
    delete this->adopter;
    this->adopter = nullptr;
}

void Pet::getInfo() {
    cout << endl << endl << "Name: " << getName() << endl
         << "ID: " << getID() << endl
         << "Days in Shelter: " << getDays_in_shelter() << endl
         << "Color: " << getColor() << endl
         << "Animal Type: " << getAnimal_Type() << endl;
    if (adopter) {
        cout << "Adopter Name: " << adopter->getName() << endl
             << "Adopter Phone: " << adopter->getPhoneNumber() << endl;
    } else {
        cout << "No Adopter Assigned" << endl;
    }
}