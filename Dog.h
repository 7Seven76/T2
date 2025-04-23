//
// Created by Ryank on 4/17/2025.
//

#ifndef DOG_H
#define DOG_H
#include "Pet.h"

class Dog : public Pet{
public:
    Dog();
    string getBreed();
    string getHairLength();
    
    virtual void getInfo();

    void setBreed(const string Breed);
    void setHairLength(const string Hair_Length);

private:
    string Breed;
    string Hair_Length;
};

#endif // DOG_H