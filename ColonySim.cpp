#include <iostream>
#include <string>

using namespace std;

class Colony {
private:
    string name;
    int population;

public:
    Colony(string n, int pop) : name(n), population(pop) {}

    void growPopulation(int amount) {
        this->population += amount; // Using this pointer to access population
        cout << "The population of " << this->name << " has grown by " << amount << ". New population: " << this->population << endl;
    }

    void reportPopulation() {
        cout << "The current population of " << this->name << " is " << this->population << "." << endl;
    }

    // Getter methods
    string getName() {
        return this->name; // Using this pointer in a getter method
    }

    int getPopulation() {
        return this->population;
    }
};

class Alien {
private:
    string speciesName;
    int strength;

public:
    Alien(string sName, int str) : speciesName(sName), strength(str) {}

    void attack(Colony &colony) {
        cout << "The " << this->speciesName << " attacks the colony " << colony.getName() << "!" << endl;
        if (this->strength > colony.getPopulation()) {
            cout << "The " << this->speciesName << " is too strong! The colony " << colony.getName() << " is overrun." << endl;
        } else {
            cout << "The colony " << colony.getName() << " defends itself against the " << this->speciesName << "." << endl;
        }
    }

    string getSpeciesName() {
        return this->speciesName; // Using this pointer in another getter
    }
};

// Main function
int main() {
    Colony earthColony("Earth Colony", 100);
    Alien alienSpecies("Xenomorph", 120);

    // Using the member functions
    earthColony.reportPopulation();
    earthColony.growPopulation(20);
    alienSpecies.attack(earthColony);

    return 0;
}
