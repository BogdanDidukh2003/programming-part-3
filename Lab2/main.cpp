#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define INPUT_FILEPATH "../discnt.in"
#define OUTPUT_FILEPATH "../discnt.out"

using namespace std;

int main() {
    vector<double> prices;
    double discount, cost = 0;

    ifstream inputFile;
    inputFile.open(INPUT_FILEPATH, ios::in);
    string line, number;
    getline(inputFile, line);
    stringstream s(line);
    while (getline(s, number, ' ')) {
        prices.push_back(stod(number));
    }
    inputFile >> discount;
    discount = 1 - discount * 0.01;
    inputFile.close();

    sort(prices.begin(), prices.end());

    int productsNumber = prices.size();
    int discountProductsLeftIndex = productsNumber - floor(productsNumber / 3);

    int count;
    for (count = 0; count < discountProductsLeftIndex; count++) {
        cost += prices[count];
    }
    for (count = discountProductsLeftIndex; count < productsNumber; count++) {
        cost += prices[count] * discount;
    }

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << fixed << setprecision(2) << cost << endl;
    outputFile.close();

    return 0;
}
