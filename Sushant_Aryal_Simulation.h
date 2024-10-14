#ifndef SUSHANT_ARYAL_SIMULATION_H
#define SUSHANT_ARYAL_SIMULATION_H

#include "Sushant_Aryal_Queue.h"
#include <vector>
#include <string>

class Simulation : private Queue<string> {
private:
    vector<string> eliminated;
    string survivor;
    int skip_number;

    void RunSimulation() {
        string next_person;
        while (GetCount() > 1) {
            for (int i = 0; i < skip_number - 1; ++i) {
                Dequeue(next_person);
                Enqueue(next_person);
            }
            Dequeue(next_person);
            eliminated.push_back(next_person);
        }
        Dequeue(survivor);
    }

public:
    Simulation(const vector<string> &people, int skip) {
        RunNewSimulation(people, skip);
    }

    void RunNewSimulation(const vector<string> &people, int skip) {
        // Clear previous data
        while (!IsEmpty()) {
            string temp;
            Dequeue(temp);
        }
        eliminated.clear();
        survivor = "";
        skip_number = skip;

        // Load queue
        for (const string &person : people) {
            Enqueue(person);
        }

        // Run the simulation
        RunSimulation();
    }

    vector<string> GetEliminationList() const {
        return eliminated;
    }

    string GetSurvivor() const {
        return survivor;
    }
};

#endif // SUSHANT_ARYAL_SIMULATION_H
