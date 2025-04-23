//
// Created by Ryank on 4/17/2025.
//

#ifndef CAT_H
#define CAT_H
#include "Pet.h"


class Cat : public Pet{
  public:
    Cat();
    string getBreed() const;
    string getCoat_Pattern() const;

    void virtual getInfo();

    void setBreed(string Breed);
    void setCoat_Pattern(string Coat_Pattern);


  private:
    string Breed;
    string Coat_Pattern;


};



#endif //CAT_H
