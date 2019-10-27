#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <cmath>

#define INPUT_FILEPATH "../data.in"
#define OUTPUT_FILEPATH "../data.out"

using namespace std;

int main() {
    int workersNumber, beerTypesNumber;

    ifstream inputFile;
    inputFile.open(INPUT_FILEPATH, ios::in);
    inputFile >> workersNumber;
    inputFile >> beerTypesNumber;

    set<int> beersToWorkers[beerTypesNumber];
    {
        string worker;
        for (int currentWorker = 0; currentWorker < workersNumber; currentWorker++) {
            inputFile >> worker;
            for (int beerType = 0; beerType < beerTypesNumber; beerType++)
                if (worker[beerType] == 'Y')
                    beersToWorkers[beerType].insert(currentWorker);
        }
    }
    inputFile.close();
    int minNeededBeerTypesNumber = beerTypesNumber;

    {
        set<int> allCovered;
        for (int i = 0; i < workersNumber; i++)
            allCovered.insert(i);
        set<int> currentCoverage;

        unsigned long partitionsNumber = pow(2, beerTypesNumber);
        unsigned long partitionIndex, beerType, neededBeerTypes;

        for (partitionIndex = 0; partitionIndex < partitionsNumber; partitionIndex++) {
            neededBeerTypes = 0;
            currentCoverage.clear();
            for (beerType = 0; beerType < beerTypesNumber; beerType++) {
                if (partitionIndex & ((unsigned long)1 << beerType)) {
                    neededBeerTypes++;
                    for (const int& worker: beersToWorkers[beerType]) {
                        currentCoverage.insert(worker);
                    }
                }
            }
            if (currentCoverage == allCovered && neededBeerTypes < minNeededBeerTypesNumber) {
                minNeededBeerTypesNumber = (int)neededBeerTypes;
            }
        }
    }

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << minNeededBeerTypesNumber << endl;
    outputFile.close();

    return 0;
}
