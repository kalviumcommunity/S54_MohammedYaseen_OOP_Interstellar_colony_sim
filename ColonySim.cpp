#include <iostream>
#include <string>

using namespace std;

class Colony {
protected:
    string name;
    int population;

public:
    Colony(string n = "Unknown", int pop = 0) : name(n), population(pop) {}

    virtual void report() const {
        cout << "Colony Name: " << name << ", Population: " << population << endl;
    }

    int getPopulation() const {
        return population;
    }

    void setPopulation(int pop) {
        population = pop;
    }
};


class SpaceColony : public Colony {
private:
    string planetName;

public:
    SpaceColony(string n, int pop, string planet)
        : Colony(n, pop), planetName(planet) {}

    void report() const override {
        cout << "Space Colony Name: " << name
             << ", Planet: " << planetName
             << ", Population: " << population << endl;
    }
};

class Alien {
protected:
    string speciesName;
    int strength;

public:
    Alien(string sName = "Unknown", int str = 0)
        : speciesName(sName), strength(str) {}

    virtual void attack(Colony &colony) {
        cout << "The " << speciesName << " attacks the colony!" << endl;
        if (strength > colony.getPopulation()) {
            cout << "The colony is overrun by " << speciesName << "." << endl;
        } else {
            cout << "The colony defends itself successfully!" << endl;
        }
    }
};

class HostileAlien : public Alien {
private:
    int aggressionLevel;

public:
    HostileAlien(string sName, int str, int aggression)
        : Alien(sName, str), aggressionLevel(aggression) {}

    void attack(Colony &colony) override {
        cout << "The hostile alien " << speciesName
             << " with aggression level " << aggressionLevel
             << " attacks!" << endl;
        Alien::attack(colony);
    }
};

int main() {
    SpaceColony earth("Earth Colony", 1000, "Earth");
    SpaceColony mars("Mars Colony", 500, "Mars");

    HostileAlien xenomorph("Xenomorph", 800, 9);

    earth.report();
    xenomorph.attack(earth);

    mars.report();
    xenomorph.attack(mars);

    return 0;
}
