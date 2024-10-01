#include <iostream>
#include <string>

using namespace std;

class Colony {
private:
    string name;
    int population;
    static int total_colonies;

public:
    Colony(string n = "Unknown", int pop = 0) : name(n), population(pop) {
        total_colonies++;
    }

    static int getTotalColonies() {
        return total_colonies;
    }

    void growPopulation(int amount) {
        this->population += amount; 
        cout << "The population of " << this->name << " has grown by " << amount << ". New population: " << this->population << endl;
    }

    void reportPopulation() {
        cout << "The current population of " << this->name << " is " << this->population << "." << endl;
    }

   
    int getPopulation() {
        return this->population;
    }
};

int Colony::total_colonies = 0;

class Alien {
private:
    string speciesName;
    int strength;
    static int total_attacks;

public:
    Alien(string sName = "Unknown", int str = 0) : speciesName(sName), strength(str) {}

    void attack(Colony &colony) {
        total_attacks++;
        cout << "The " << this->speciesName << " attacks the colony!" << endl;
        if (this->strength > colony.getPopulation()) {  // Calling the getPopulation() method here
            cout << "The " << this->speciesName << " is too strong! The colony is overrun." << endl;
        } else {
            cout << "The colony defends itself against the " << this->speciesName << "." << endl;
        }
    }

    static int getTotalAttacks() {
        return total_attacks;
    }
};

int Alien::total_attacks = 0;

int main() {
    // Create colonies
    Colony* colonies = new Colony[3]{
        Colony("Earth Colony", 100),
        Colony("Mars Colony", 150),
        Colony("Jupiter Colony", 80)
    };

    // Create aliens
    Alien* alienSpecies = new Alien[2]{
        Alien("Xenomorph", 120),
        Alien("Predator", 200)
    };

    // Report population and perform attacks
    colonies[0].growPopulation(50);
    alienSpecies[0].attack(colonies[0]);
    alienSpecies[1].attack(colonies[2]);

    // Output total colonies and alien attacks using static member functions
    cout << "Total colonies created: " << Colony::getTotalColonies() << endl;
    cout << "Total alien attacks: " << Alien::getTotalAttacks() << endl;

    // Free memory
    delete[] colonies;
    delete[] alienSpecies;

    return 0;
}
