#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "models/Helicopter.h"
#include "models/HelicoptersManager.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<Helicopter> helicopters;

    string filepath = "../data.txt";
    ifstream file;
    file.open(filepath, ios::in);
    vector<string> row;
    string line, field, temp;

    while (file >> line) {
        row.clear();
        stringstream s(line);
        while (getline(s, field, ',')) {
            row.push_back(field);
        }
        helicopters.emplace_back(Helicopter(stoi(row[0]), row[1], stoi(row[2])));
    }
    file.close();
    HelicoptersManager manager(helicopters);

    cout << "\t\tInsertion" << "\n\n";
    cout << "Before sorting:" << "\n";
    cout << manager << "\n";
    auto startInsertion = high_resolution_clock::now();
    manager.sortByMaxSpeed();
    auto stopInsertion = high_resolution_clock::now();
    cout << "After sorting:" << "\n";
    cout << manager << "\n";
    cout << "Time of execution: " << duration_cast<microseconds>(stopInsertion - startInsertion).count() << " μs\n";
    cout << "Number of comparisons: " << manager.getInsertionComparisons() << "\n";
    cout << "Number of exchanges: " << manager.getInsertionExchanges() << "\n\n";

    cout << "\t\tMerge" << "\n\n";
    cout << "Before sorting" << "\n";
    cout << manager << "\n";
    auto startMerge = high_resolution_clock::now();
    manager.sortByPassengersNumber(true);
    auto stopMerge = high_resolution_clock::now();
    cout << "After sorting:" << "\n";
    cout << manager;
    cout << "Time of execution: " << duration_cast<microseconds>(stopMerge - startMerge).count() << " μs\n";
    cout << "Number of comparisons: " << manager.getMergeComparisons() << "\n";
    cout << "Number of exchanges: " << manager.getMergeExchanges() << "\n";

    return 0;
}
