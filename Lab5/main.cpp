#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

#define ONE '1'
#define OUTPUT_FILEPATH "../data.out"

using namespace std;
using namespace boost::multiprecision;

inline uint256_t convertBinaryToUnsignedInt(const string &binary);

inline bool isNumberCompatibleForBase(uint256_t number, const uint64_t &base);

inline bool isBinaryCompatibleForBase(const string &binary, const uint64_t &base);

inline unsigned int solution(const string &strNumber, const unsigned int &baseNumber);

int main() {
    const vector<string> INPUT_FILEPATH = {"../data1.in", "../data2.in", "../data3.in", "../data4.in"};

    uint256_t number = 0;
    string strNumber;
    unsigned int baseNumber;
    int minParts = 0;

    int fileNumber;
    cout << "Enter number of file to open (from 1 to " << INPUT_FILEPATH.size() << "): ";
    cin >> fileNumber;

    ifstream inputFile;
    inputFile.open(INPUT_FILEPATH[fileNumber - 1], ios::in);
    inputFile >> strNumber;
    inputFile >> baseNumber;

    minParts = int(solution(strNumber, baseNumber));
    if (minParts >= strNumber.size()) {
        minParts = -1;
    }

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << minParts << endl;
    outputFile.close();

    return 0;
}

inline uint256_t convertBinaryToUnsignedInt(const string &binary) {
    uint256_t decimal = 0;
    int size = binary.size();
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == ONE) {
            decimal += uint256_t(pow(2, (size - i - 1)));
        }
    }
    return decimal;
}

inline bool isNumberCompatibleForBase(uint256_t number, const uint64_t &base) {
    if (number == 1) {
        return true;
    }

    uint256_t previous, remainder;

    do {
        previous = number;
        number /= base;
        remainder = previous - number * base;
    } while (number > 1 && !remainder);

    return (number == 1 && !remainder);
}

inline bool isBinaryCompatibleForBase(const string &binary, const uint64_t &base) {
    return isNumberCompatibleForBase(convertBinaryToUnsignedInt(binary), base);
}

inline unsigned int solution(const string &strNumber, const unsigned int &baseNumber) {
    if (isBinaryCompatibleForBase(strNumber, baseNumber)) {
        return 1;
    }
    unsigned int currentSolution = strNumber.size();
    set<unsigned int> allSolutions;

    for (unsigned long k = 1; k < strNumber.size(); k++) {
        if (isBinaryCompatibleForBase(strNumber.substr(k, strNumber.size() - 1), baseNumber)) {
            allSolutions.insert(solution(strNumber.substr(0, k), baseNumber) + 1);
        }
    }

    for (const auto &sol : allSolutions) {
        if (sol < currentSolution) {
            currentSolution = sol;
        }
    }

    return currentSolution;
}
