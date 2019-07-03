#include "HelicoptersManager.h"

HelicoptersManager::HelicoptersManager(const vector<Helicopter> &helicopters) : helicopters(helicopters) {}

const vector<Helicopter> &HelicoptersManager::getHelicopters() const {
    return helicopters;
}

void HelicoptersManager::setHelicopters(const vector<Helicopter> &helicopters) {
    HelicoptersManager::helicopters = helicopters;
}

ostream &operator<<(ostream &os, const HelicoptersManager &manager) {
    for (auto const &helicopter : manager.helicopters) {
        os << "helicopter{" << helicopter << "}\n";
    }
    return os;
}

int HelicoptersManager::getInsertionComparisons() const {
    return insertionComparisons;
}

int HelicoptersManager::getInsertionExchanges() const {
    return insertionExchanges;
}

int HelicoptersManager::getMergeComparisons() const {
    return mergeComparisons;
}

int HelicoptersManager::getMergeExchanges() const {
    return mergeExchanges;
}

void HelicoptersManager::sortByMaxSpeed(bool reverse) {
    int len = helicopters.size();

    int element, active;
    for (element = 1; element < len; element++) {
        active = element - 1;
        while (active >= 0
               && insertionComparisons++
               && ((!reverse && helicopters[element].getMaxSpeed() < helicopters[active].getMaxSpeed())
                   || (reverse && helicopters[element].getMaxSpeed() > helicopters[active].getMaxSpeed()))) {
            Helicopter swapper = helicopters[element];
            helicopters[element] = helicopters[active];
            helicopters[active] = swapper;
            insertionExchanges++;
            element = active;
            active--;
        }
    }
}

void HelicoptersManager::sortByPassengersNumber(bool reverse) {
    vector<Helicopter> resultsArray(helicopters.size());
    mergeSortRecursive(helicopters, resultsArray, 0, helicopters.size() - 1, reverse);
}

void HelicoptersManager::mergeSortRecursive(vector<Helicopter> &array, vector<Helicopter> &resultsArray,
                                            int left, int right, bool reverse) {
    if (left < right) {
        int middle = (left + right) / 2;

        mergeSortRecursive(array, resultsArray, left, middle, reverse);
        mergeSortRecursive(array, resultsArray, middle + 1, right, reverse);

        merge(array, resultsArray, left, middle + 1, right, reverse);
    }
}

void HelicoptersManager::merge(vector<Helicopter> &array, vector<Helicopter> &resultsArray,
                               int leftBegin, int rightBegin, int rightEnd, bool reverse) {
    int leftEnd = rightBegin - 1;
    int leftReadPosition = leftBegin;
    int rightReadPosition = rightBegin;
    int resultWritePosition = leftBegin;

    while (leftReadPosition <= leftEnd && rightReadPosition <= rightEnd) {
        if (compareByPassengersNumber(array[leftReadPosition], array[rightReadPosition], reverse)) {
            resultsArray[resultWritePosition] = array[leftReadPosition];
            leftReadPosition++;
        } else {
            resultsArray[resultWritePosition] = array[rightReadPosition];
            rightReadPosition++;
        }
        mergeExchanges++;
        resultWritePosition++;
    }

    while (leftReadPosition <= leftEnd) {
        resultsArray[resultWritePosition] = array[leftReadPosition];
        leftReadPosition++;
        resultWritePosition++;
        mergeExchanges++;
    }

    while (rightReadPosition <= rightEnd) {
        resultsArray[resultWritePosition] = array[rightReadPosition];
        rightReadPosition++;
        resultWritePosition++;
        mergeExchanges++;
    }

    for (int i = leftBegin; i <= rightEnd; i++) {
        array[i] = resultsArray[i];
    }
}

bool HelicoptersManager::compareByPassengersNumber(Helicopter &left, Helicopter &right, bool reverse) {
    mergeComparisons++;
    if (!reverse)
        return left.getPassengersNumber() < right.getPassengersNumber();
    return left.getPassengersNumber() > right.getPassengersNumber();
}
