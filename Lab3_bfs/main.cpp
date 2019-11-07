#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>

#define OUTPUT_FILEPATH "../data.out"

using namespace std;

int main() {
    const vector<string> INPUT_FILEPATH = {"../data1.in", "../data2.in", "../data3.in"};
    int pathLength;

    int fileNumber;
    cout << "Enter number of file to open (from 1 to " << INPUT_FILEPATH.size() << "): ";
    cin >> fileNumber;

    queue<int> inputData;
    int edgesNumber, verticesNumber, startVertex;

    ifstream inputFile;
    inputFile.open(INPUT_FILEPATH[--fileNumber], ios::in);
    inputFile >> edgesNumber;
    inputFile >> startVertex;

    int maxVertex = 0, vertex;
    for (int i = 0; i < edgesNumber * 2; i++) {
        inputFile >> vertex;
        if (vertex > maxVertex) {
            maxVertex = vertex;
        }
        inputData.push(vertex);
    }
    inputFile.close();
    verticesNumber = maxVertex + 1;

    vector<int> adjacencyList[verticesNumber];

    int vertexFrom, vertexTo;
    while (!inputData.empty()) {
        vertexFrom = inputData.front();
        inputData.pop();
        vertexTo = inputData.front();
        inputData.pop();
        adjacencyList[vertexFrom].push_back(vertexTo);
    }

    queue<int> verticesToVisit;
    int wave[verticesNumber];
    for (auto& value : wave) {
        value = 0;
    }
    bool waveIsAdded[verticesNumber];
    for (auto& state : waveIsAdded) {
        state = false;
    }
    bool visited[verticesNumber];
    for (auto& state : visited) {
        state = false;
    }

    verticesToVisit.push(startVertex);

    int currentVertex, lastVertex = startVertex;
    while (!verticesToVisit.empty()) {
        currentVertex = verticesToVisit.front();
        verticesToVisit.pop();
        lastVertex = currentVertex;

        if (visited[currentVertex]) {
            continue;
        }
        visited[currentVertex] = true;

        for (auto& connectedVertex : adjacencyList[currentVertex]) {
            if (!visited[connectedVertex]) {
                verticesToVisit.push(connectedVertex);
                if (!waveIsAdded[connectedVertex]) {
                    wave[connectedVertex] = wave[currentVertex] + 1;
                    waveIsAdded[connectedVertex] = true;
                }
            }
        }
    }
    pathLength = wave[lastVertex];

    ofstream outputFile;
    outputFile.open(OUTPUT_FILEPATH, ios::out);
    outputFile << pathLength << endl;
    outputFile.close();

    return 0;
}
