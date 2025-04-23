#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "IntrestedAdopter.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int CAP = 10;

// Loads the file and reads the contents of it.
// Updated load_shelter function to handle adopter information
void load_shelter(const string& file, Pet **&data, int &size) {
    ifstream ifs(file);
    if (ifs.fail()) {
        cout << "Failed to open file." << endl;
        return;
    }

    string line;
    while (getline(ifs, line)) {
        if (size >= CAP) {
            CAP = CAP + CAP / 2;
            Pet **new_data = new Pet*[CAP];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }

        stringstream ss(line);
        string type, name, color, animalType, num_str, adopterName, adopterPhone;
        int id = 0, days_in_shelter = 0;

        getline(ss, type, ','); // Type of pet: Pet, Dog, or Cat
        getline(ss, name, ',');
        getline(ss, num_str, ',');
        id = stoi(num_str);
        getline(ss, num_str, ',');
        days_in_shelter = stoi(num_str);
        getline(ss, color, ',');
        getline(ss, animalType, ',');

        if (type == "Dog") {
            Dog *dog = new Dog();
            dog->setName(name);
            dog->setID(id);
            dog->setDays_in_shelter(days_in_shelter);
            dog->setColor(color);
            dog->setAnimal_Type(animalType);

            string breed, hairLength;
            getline(ss, breed, ',');
            getline(ss, hairLength, ',');
            dog->setBreed(breed);
            dog->setHairLength(hairLength);

            getline(ss, adopterName, ',');
            getline(ss, adopterPhone, ',');
            if (!adopterName.empty() && adopterName != "None" && !adopterPhone.empty() && adopterPhone != "None") {
                InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
                dog->setAdopter(adopter);
            }

            data[size] = dog;
        } else if (type == "Cat") {
            Cat *cat = new Cat();
            cat->setName(name);
            cat->setID(id);
            cat->setDays_in_shelter(days_in_shelter);
            cat->setColor(color);
            cat->setAnimal_Type(animalType);

            string breed, coatPattern;
            getline(ss, breed, ',');
            getline(ss, coatPattern, ',');
            cat->setBreed(breed);
            cat->setCoat_Pattern(coatPattern);

            getline(ss, adopterName, ',');
            getline(ss, adopterPhone, ',');
            if (!adopterName.empty() && adopterName != "None" && !adopterPhone.empty() && adopterPhone != "None") {
                InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
                cat->setAdopter(adopter);
            }

            data[size] = cat;
        } else {
            Pet *pet = new Pet();
            pet->setName(name);
            pet->setID(id);
            pet->setDays_in_shelter(days_in_shelter);
            pet->setColor(color);
            pet->setAnimal_Type(animalType);

            getline(ss, adopterName, ',');
            getline(ss, adopterPhone, ',');
            if (!adopterName.empty() && adopterName != "None" && !adopterPhone.empty() && adopterPhone != "None") {
                InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
                pet->setAdopter(adopter);
            }

            data[size] = pet;
        }

        size++;
    }

    cout << "Shelter data successfully loaded!" << endl;
}

// Prints all pets in the shelter
void print(Pet **&pets, int &numPets) {
    cout << "Animals in shelter:" << endl << endl;
    for (int i = 0; i < numPets; ++i) {
        pets[i]->getInfo();
    }
}

//Adds pets as well as adopter info
void add_pet(Pet **&data, int &size) {
        Pet **new_data = new Pet*[CAP];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;

    string type;
    cout << "Enter type of pet (Dog/Cat/Other): ";
    cin >> type;

    if (type == "Dog") {
        Dog *dog = new Dog();
        string breed, hairLength, name, color, animalType;
        int id, days_in_shelter;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter days in shelter: ";
        cin >> days_in_shelter;
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter animal type: ";
        cin >> animalType;

        cout << "Enter breed: ";
        cin >> breed;
        cout << "Enter hair length: ";
        cin >> hairLength;

        dog->setName(name);
        dog->setID(id);
        dog->setDays_in_shelter(days_in_shelter);
        dog->setColor(color);
        dog->setAnimal_Type(animalType);
        dog->setBreed(breed);
        dog->setHairLength(hairLength);

        string adopterResponse;
        cout << "Is there an interested adopter? (yes/no): ";
        cin >> adopterResponse;

        if (adopterResponse == "yes") {
            string adopterName, adopterPhone;
            cout << "Enter adopter name: ";
            cin >> adopterName;
            cout << "Enter adopter phone number: ";
            cin >> adopterPhone;

            InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
            dog->setAdopter(adopter);
        }

        data[size] = dog;

    } else if (type == "Cat") {
        Cat *cat = new Cat();
        string breed, coatPattern, name, color, animalType;
        int id, days_in_shelter;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter days in shelter: ";
        cin >> days_in_shelter;
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter animal type: ";
        cin >> animalType;

        cout << "Enter breed: ";
        cin >> breed;
        cout << "Enter coat pattern: ";
        cin >> coatPattern;

        cat->setName(name);
        cat->setID(id);
        cat->setDays_in_shelter(days_in_shelter);
        cat->setColor(color);
        cat->setAnimal_Type(animalType);
        cat->setBreed(breed);
        cat->setCoat_Pattern(coatPattern);

        string adopterResponse;
        cout << "Is there an interested adopter? (yes/no): ";
        cin >> adopterResponse;

        if (adopterResponse == "yes") {
            string adopterName, adopterPhone;
            cout << "Enter adopter name: ";
            cin >> adopterName;
            cout << "Enter adopter phone number: ";
            cin >> adopterPhone;

            InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
            cat->setAdopter(adopter);
        }

        data[size] = cat;

    } else {
        Pet *pet = new Pet();
        string name, color, animalType;
        int id, days_in_shelter;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter days in shelter: ";
        cin >> days_in_shelter;
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter animal type: ";
        cin >> animalType;

        pet->setName(name);
        pet->setID(id);
        pet->setDays_in_shelter(days_in_shelter);
        pet->setColor(color);
        pet->setAnimal_Type(animalType);

        string adopterResponse;
        cout << "Is there an interested adopter? (yes/no): ";
        cin >> adopterResponse;

        if (adopterResponse == "yes") {
            string adopterName, adopterPhone;
            cout << "Enter adopter name: ";
            cin >> adopterName;
            cout << "Enter adopter phone number: ";
            cin >> adopterPhone;

            InterestedAdopter *adopter = new InterestedAdopter(adopterName, adopterPhone);
            pet->setAdopter(adopter);
        }

        data[size] = pet;
    }

    size++;
}

// Finds the oldest resident in the shelter
void find_oldest(Pet **data, int size) {
    if (size == 0) {
        cout << "No pets available to find the oldest resident." << endl;
        return;
    }

    int max_days = data[0]->getDays_in_shelter();
    int index = 0;

    for (int i = 1; i < size; ++i) {
        if (data[i]->getDays_in_shelter() > max_days) {
            max_days = data[i]->getDays_in_shelter();
            index = i;
        }
    }

    cout << "The oldest resident is " << data[index]->getName()
         << " with " << data[index]->getDays_in_shelter() << " days in shelter." << endl;
}

// Saves the shelter data to a file
void save(const string file, Pet **&data, int &size) {
    ofstream ofs(file);
    if (ofs.fail()) {
        cout << "Failed to open file." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        data[i]->setDays_in_shelter(data[i]->getDays_in_shelter() + 1);

        if (typeid(*data[i]) == typeid(Dog)) {
            Dog *dog = static_cast<Dog *>(data[i]);
            ofs << "Dog,"
                << dog->getName() << ","
                << dog->getID() << ","
                << dog->getDays_in_shelter() << ","
                << dog->getColor() << ","
                << dog->getAnimal_Type() << ","
                << dog->getBreed() << ","
                << dog->getHairLength() << "\n";
        } else if (typeid(*data[i]) == typeid(Cat)) {
            Cat *cat = static_cast<Cat *>(data[i]);
            ofs << "Cat,"
                << cat->getName() << ","
                << cat->getID() << ","
                << cat->getDays_in_shelter() << ","
                << cat->getColor() << ","
                << cat->getAnimal_Type() << ","
                << cat->getBreed() << ","
                << cat->getCoat_Pattern() << "\n";
        } else {
            ofs << "Pet,"
                << data[i]->getName() << ","
                << data[i]->getID() << ","
                << data[i]->getDays_in_shelter() << ","
                << data[i]->getColor() << ","
                << data[i]->getAnimal_Type() << "\n";
        }
    }

    cout << "Shelter data successfully saved!" << endl;
}

int main() {
    Pet** data = new Pet*[CAP];
    int size = 0;

    string use_program;
    // Intro to the program
    cout << "Welcome!" << endl
         << "This is a program that manages and stores pet shelter information!" << endl
         << "Would you like to use the program? (yes/no): ";
    cin >> use_program;

    if (use_program == "yes") {
        string answer, file, file_choice;
        cout << "Would you like to load an existing file or start without a file? Enter: yes/no: ";
        cin >> file_choice;

        if (file_choice == "yes") {
            cout << "Enter the file name to load: ";
            cin >> file;
            load_shelter(file, data, size);
        } else if (file_choice == "no") {
            cout << "Starting with an empty shelter." << endl;
        } else {
            cout << "Invalid option. Exiting program." << endl;
            delete[] data;
            return 0;
        }

        // Main menu
        while (true) {
            cout << endl
                 << "Menu Options:" << endl
                 << "1. Print Shelter" << endl
                 << "2. Add Pet" << endl
                 << "3. Find Oldest Resident" << endl
                 << "4. Save Shelter" << endl
                 << "5. Exit Program" << endl
                 << "Enter your choice: ";
            cin >> answer;

            if (answer == "1") {
                print(data, size);
            } else if (answer == "2") {
                add_pet(data, size);
            } else if (answer == "3") {
                find_oldest(data, size);
            } else if (answer == "4") {
                cout << "Enter the file name to save: ";
                cin >> file;
                save(file, data, size);
            } else if (answer == "5") {
                cout << "Thank you for using the program!" << endl;
                break;
            } else {
                cout << "Invalid option. Please try again!" << endl;
            }
        }
    } else {
        cout << "Goodbye!" << endl;
    }

    // Clean up memory
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;

    return 0;
}