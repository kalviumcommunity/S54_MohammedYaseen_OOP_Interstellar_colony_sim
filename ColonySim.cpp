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
        population += amount;
        cout << "The population of " << name << " has grown by " << amount << ". New population: " << population << endl;
    }

    void reportPopulation() {
        cout << "The current population of " << name << " is " << population << "." << endl;
    }

    // Getter methods
    string getName() {
        return name;
    }

    int getPopulation() {
        return population;
    }
};

class Alien {
private:
    string speciesName;
    int strength;

public:
    Alien(string sName, int str) : speciesName(sName), strength(str) {}

    void attack(Colony &colony) {
        cout << "The " << speciesName << " attacks the colony " << colony.getName() << "!" << endl;
        if (strength > colony.getPopulation()) {
            cout << "The " << speciesName << " is too strong! The colony " << colony.getName() << " is overrun." << endl;
        } else {
            cout << "The colony " << colony.getName() << " defends itself against the " << speciesName << "." << endl;
        }
    }

    string getSpeciesName() {
        return speciesName;
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
