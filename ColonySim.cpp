#include <iostream>
#include <string>

using namespace std;

class Colony {
private:
    string name;
    int population;
    static int totalColonies; // Static variable to track total number of colonies

public:
    Colony(string n = "Unknown", int pop = 0) : name(n), population(pop) {
        totalColonies++; // Increment total colonies count when a new colony is created
    }

    ~Colony() {
        totalColonies--; // Decrement total colonies count when a colony is destroyed
    }

    void growPopulation(int amount) {
        this->population += amount; 
        cout << "The population of " << this->name << " has grown by " << amount << ". New population: " << this->population << endl;
    }

    void reportPopulation() {
        cout << "The current population of " << this->name << " is " << this->population << "." << endl;
    }

    static void reportTotalColonies() {
        cout << "Total colonies created: " << totalColonies << endl;
    }

    string getName() {
        return this->name; 
    }

    int getPopulation() {
        return this->population;
    }
};

// Initialize the static variable
int Colony::totalColonies = 0;

class Alien {
private:
    string speciesName;
    int strength;
    static int totalAttacks; // Static variable to track total number of attacks

public:
    Alien(string sName = "Unknown", int str = 0) : speciesName(sName), strength(str) {}

    void attack(Colony &colony) {
        totalAttacks++; // Increment total attacks count when an attack happens
        cout << "The " << this->speciesName << " attacks the colony " << colony.getName() << "!" << endl;
        if (this->strength > colony.getPopulation()) {
            cout << "The " << this->speciesName << " is too strong! The colony " << colony.getName() << " is overrun." << endl;
        } else {
            cout << "The colony " << colony.getName() << " defends itself against the " << this->speciesName << "." << endl;
        }
    }

    static void reportTotalAttacks() {
        cout << "Total alien attacks: " << totalAttacks << endl;
    }

    string getSpeciesName() {
        return this->speciesName; 
    }
};

// Initialize the static variable
int Alien::totalAttacks = 0;

int main() {

    // Dynamically allocate memory for colonies and aliens
    Colony* colonies = new Colony[3] {
        Colony("Earth Colony", 100), 
        Colony("Mars Colony", 150), 
        Colony("Jupiter Colony", 80) 
    };

    Alien* alienSpecies = new Alien[2] {
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

    // Report total colonies and total attacks
    Colony::reportTotalColonies();
    Alien::reportTotalAttacks();

    // Free dynamically allocated memory
    delete[] colonies;
    delete[] alienSpecies;

    return 0;
}
