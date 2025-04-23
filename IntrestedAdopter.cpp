//
// Created by Ryank on 4/17/2025.
//

#include "IntrestedAdopter.h"

InterestedAdopter::InterestedAdopter(const string Name, const string Phone_Number){
  this->Name = Name;
  this->Phone_Number = Phone_Number;
}

string InterestedAdopter::getName() const{
  return this->Name;
}

string InterestedAdopter::getPhoneNumber() const{
  return this->Phone_Number;
}

void InterestedAdopter::setName(const string Name){
  this->Name = Name;
}

void InterestedAdopter::setPhoneNumber(const string Phone_Number){
  this->Phone_Number = Phone_Number;
}
