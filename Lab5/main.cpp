#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

#define ONE '1'
#define ZERO '0'
#define OUTPUT_FILEPATH "../data.out"
#define uint256_t boost::multiprecision::uint256_t

using namespace std;

inline string convertDecimalToBinary(uint256_t decimal);

inline set<string> findAllPossibleBinaries(const string &binary, const unsigned int &base);

inline unsigned int solutionWithPreparation(const string &binary, const unsigned int &base,
        const set<string> &allPossibleBinaries);

int main() {
    const vector<string> INPUT_FILEPATH = {"../data1.in", "../data2.in", "../data3.in", "../data4.in"};

    uint256_t number = 0;
    string binary;
    unsigned int base;
    int minParts = 0;

    int fileNumber;
    cout << "Enter number of file to open (from 1 to " << INPUT_FILEPATH.size() << "): ";
    cin >> fileNumber;

    ifstream inputFile;
    inputFile.open(INPUT_FILEPATH[fileNumber - 1], ios::in);
    inputFile >> binary;
    inputFile >> base;

    minParts = int(solutionWithPreparation(binary, base, findAllPossibleBinaries(binary, base)));
    if (minParts > binary.size()) {
        minParts = -1;
    }

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << minParts << endl;
    outputFile.close();

    return 0;
}

inline string convertDecimalToBinary(uint256_t decimal) {
    string binary;

    if (decimal == 0) {
        binary.push_back(ZERO);
        return binary;
    }

    for (int i = 0; decimal > 0; i++) {
        if (decimal % 2) {
            binary.push_back(ONE);
        } else {
            binary.push_back(ZERO);
        }
        decimal /= 2;
    }

    int length = binary.length();
    for (int i = 0; i < length / 2; i++) {
        swap(binary[i], binary[length - i - 1]);
    }

    return binary;
}

inline set<string> findAllPossibleBinaries(const string &binary, const unsigned int &base) {
    set<string> possibleBinaries;
    string possibleBinary;
    unsigned int power = 0;
    do {
        possibleBinary = convertDecimalToBinary(uint256_t(pow(base, power)));
        possibleBinaries.insert(possibleBinary);
        power++;
    } while (possibleBinary.size() <= binary.size());

    return possibleBinaries;
}

inline unsigned int solutionWithPreparation(const string &binary, const unsigned int &base,
        const set<string> &allPossibleBinaries) {
    if (allPossibleBinaries.find(binary) != allPossibleBinaries.end()) {
        return 1;
    }
    unsigned int currentSolution = binary.size() + 1;
    set<unsigned int> allSolutions;

    for (unsigned long k = 1; k < binary.size(); k++) {
        if (allPossibleBinaries.find(binary.substr(k, binary.size() - 1)) != allPossibleBinaries.end()) {
            allSolutions.insert(solutionWithPreparation(binary.substr(0, k), base, allPossibleBinaries) + 1);
        }
    }

    for (const auto &solution : allSolutions) {
        if (solution < currentSolution) {
            currentSolution = solution;
        }
    }

    return currentSolution;
}
