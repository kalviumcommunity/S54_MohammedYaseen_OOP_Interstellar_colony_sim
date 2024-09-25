#include <iostream>
#include <string>

using namespace std;

class Colony {
private:
    string name;
    int population;

public:
    Colony(string n = "Unknown", int pop = 0) : name(n), population(pop) {}

    void growPopulation(int amount) {
        this->population += amount; 
        cout << "The population of " << this->name << " has grown by " << amount << ". New population: " << this->population << endl;
    }

    void reportPopulation() {
        cout << "The current population of " << this->name << " is " << this->population << "." << endl;
    }

    string getName() {
        return this->name; 
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
    Alien(string sName = "Unknown", int str = 0) : speciesName(sName), strength(str) {}

    void attack(Colony &colony) {
        cout << "The " << this->speciesName << " attacks the colony " << colony.getName() << "!" << endl;
        if (this->strength > colony.getPopulation()) {
            cout << "The " << this->speciesName << " is too strong! The colony " << colony.getName() << " is overrun." << endl;
        } else {
            cout << "The colony " << colony.getName() << " defends itself against the " << this->speciesName << "." << endl;
        }
    }

    string getSpeciesName() {
        return this->speciesName; 
    }
};

// Main function
int main() {
    // Array of Colony objects
    Colony colonies[3] = { 
        Colony("Earth Colony", 100), 
        Colony("Mars Colony", 150), 
        Colony("Jupiter Colony", 80) 
    };

    // Array of Alien objects
    Alien alienSpecies[2] = { 
        Alien("Xenomorph", 120), 
        Alien("Predator", 200) 
    };

    // Report populations of all colonies
    for(int i = 0; i < 3; i++) {
        colonies[i].reportPopulation();
    }

    // Grow population of the first colony
    colonies[0].growPopulation(50);

    // Aliens attack different colonies
    alienSpecies[0].attack(colonies[0]);
    alienSpecies[1].attack(colonies[2]);

    return 0;
}

