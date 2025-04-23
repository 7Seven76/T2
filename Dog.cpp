//
// Created by Ryank on 4/17/2025.
//

#include "Dog.h"
#include <iostream>
using namespace std;

// Constructor
Dog::Dog() {}

// Getters
string Dog::getBreed() {
    return Breed;
}

string Dog::getHairLength() {
    return Hair_Length;
}

// Setters
void Dog::setBreed(const string Breed) {
    this->Breed = Breed;
}

void Dog::setHairLength(string Hair_Length) {
    this->Hair_Length = Hair_Length;
}

void Dog::getInfo() {
    Pet::getInfo();
    cout << "Breed: " << getBreed() << endl
         << "Hair Length: " << getHairLength() << endl;
}