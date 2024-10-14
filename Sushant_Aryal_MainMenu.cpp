#include <iostream>
#include <vector>
#include <string>
#include "Sushant_Aryal_Simulation.h"

using namespace std;

int main() {
    char choice;
    do {
        vector<string> people;
        string name;
        int skip_number;

        cout << "Enter the number of people: ";
        int num_people;
        cin >> num_people;

        for (int i = 0; i < num_people; ++i) {
            cout << "Enter name of person " << i + 1 << ": ";
            cin >> name;
            people.push_back(name);
        }

        cout << "Enter the magic number (skip number): ";
        cin >> skip_number;

        Simulation simulation(people, skip_number);

        cout << "Order of elimination:\n";
        vector<string> eliminated = simulation.GetEliminationList();
        for (const string &person : eliminated) {
            cout << person << " was eliminated.\n";
        }

        cout << "The last person alive is: " << simulation.GetSurvivor() << endl;

        cout << "Do you want to run another simulation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
