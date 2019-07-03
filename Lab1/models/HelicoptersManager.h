#ifndef LAB1_HELICOPTERSMANAGER_H
#define LAB1_HELICOPTERSMANAGER_H


#include <vector>
#include <ostream>
#include "Helicopter.h"

using namespace std;

class HelicoptersManager {
private:
    vector<Helicopter> helicopters;

    int insertionComparisons = 0, insertionExchanges = 0, mergeComparisons = 0, mergeExchanges = 0;

    void mergeSortRecursive(vector<Helicopter> &array, vector<Helicopter> &resultsArray,
                            int left, int right, bool reverse);

    void merge(vector<Helicopter> &array, vector<Helicopter> &resultsArray, int leftBegin,
               int rightBegin, int rightEnd, bool reverse);

    bool compareByPassengersNumber(Helicopter &left, Helicopter &right, bool reverse);

public:
    HelicoptersManager(const vector<Helicopter> &helicopters);

    const vector<Helicopter> &getHelicopters() const;

    void setHelicopters(const vector<Helicopter> &helicopters);

    int getInsertionComparisons() const;

    int getInsertionExchanges() const;

    int getMergeComparisons() const;

    int getMergeExchanges() const;

    friend ostream &operator<<(ostream &os, const HelicoptersManager &manager);

    void sortByMaxSpeed(bool reverse = false);

    void sortByPassengersNumber(bool reverse = false);
};


#endif //LAB1_HELICOPTERSMANAGER_H
