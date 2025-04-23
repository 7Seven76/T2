//
// Created by Ryank on 4/17/2025.
//

#ifndef INTERESTEDADOPTER_H
#define INTERESTEDADOPTER_H

#include <iostream>
using namespace std;


class InterestedAdopter {
public:
    InterestedAdopter(const string Name, const string Phone_Number);

    string getName() const;
    string getPhoneNumber() const;

    void setName(const string Name);
    void setPhoneNumber(const string Phone_Number);

private:
    string Name;
    string Phone_Number;
};

#endif // INTERESTEDADOPTER_H