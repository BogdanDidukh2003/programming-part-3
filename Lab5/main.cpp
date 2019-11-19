#include <iostream>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

#define ONE '1'
#define ZERO '0'

#define OUTPUT_FILEPATH "../data.out"

using namespace std;
using namespace boost::multiprecision;

uint256_t convertBinaryToUnsignedInt(const string &binary);

bool isNumberCompatibleForBase(uint256_t number, const uint64_t& base);

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

    // -----------------------------------------------------------------------------------------------------------------

    // -------------- Algorithm --------------

    // -----------------------------------------------------------------------------------------------------------------

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << minParts << endl;
    outputFile.close();

    return 0;
}

uint256_t convertBinaryToUnsignedInt(const string &binary) {
    uint256_t decimal = 0;
    int size = binary.size();
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == ONE) {
            decimal += uint256_t(pow(2, (size - i - 1)));
        }
    }
    return decimal;
}

bool isNumberCompatibleForBase(uint256_t number, const uint64_t& base) {
    uint256_t previous, remainder;

    do {
        previous = number;
        number /= base;
        remainder = previous - number * base;
    } while (number > 1 && !remainder);

    return (number == 1 && !remainder);
}
