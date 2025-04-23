//
// Created by Ryank on 4/17/2025.
//

#include "Cat.h"
#include <iostream>
using namespace std;


Cat::Cat() : Breed(), Coat_Pattern() {}

// Getters
std::string Cat::getBreed() const {
    return Breed;
}

std::string Cat::getCoat_Pattern() const {
    return Coat_Pattern;
}

// Setters
void Cat::setBreed(string Breed) {
    this->Breed = Breed;
}

void Cat::setCoat_Pattern(string Coat_Pattern) {
    this->Coat_Pattern = Coat_Pattern;
}

void Cat::getInfo() {
    Pet::getInfo();
    cout << "Breed: " << getBreed() << endl
         << ", Coat Pattern: " << getCoat_Pattern() << endl;
}
