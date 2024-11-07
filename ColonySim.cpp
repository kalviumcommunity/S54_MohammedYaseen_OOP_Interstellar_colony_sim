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

    string getName() const {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    int getPopulation() const {
        return population;
    }

    void setPopulation(int pop) {
        population = pop;
    }

    void growPopulation(int amount) {
        population += amount;
        cout << "The population of " << name << " has grown by " << amount << ". New population: " << population << endl;
    }

    void reportPopulation() const {
        cout << "The current population of " << name << " is " << population << "." << endl;
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

    static int getTotalAttacks() {
        return total_attacks;
    }

    string getSpeciesName() const {
        return speciesName;
    }

    void setSpeciesName(string sName) {
        speciesName = sName;
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int str) {
        strength = str;
    }

    void attack(Colony &colony) {
        total_attacks++;
        cout << "The " << speciesName << " attacks the colony!" << endl;
        if (strength > colony.getPopulation()) { 
            cout << "The " << speciesName << " is too strong! The colony is overrun." << endl;
        } else {
            cout << "The colony defends itself against the " << speciesName << "." << endl;
        }
    }
};

int Alien::total_attacks = 0;

int main() {
    Colony* colonies = new Colony[3]{
        Colony("Earth Colony", 100),
        Colony("Mars Colony", 150),
        Colony("Jupiter Colony", 80)
    };

    Alien* alienSpecies = new Alien[2]{
        Alien("Xenomorph", 120),
        Alien("Predator", 200)
    };

    colonies[0].growPopulation(50);
    alienSpecies[0].attack(colonies[0]);
    alienSpecies[1].attack(colonies[2]);

    cout << "Total colonies created: " << Colony::getTotalColonies() << endl;
    cout << "Total alien attacks: " << Alien::getTotalAttacks() << endl;

    delete[] colonies;
    delete[] alienSpecies;

    return 0;
}
