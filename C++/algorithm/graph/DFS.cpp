#include <iostream>
using namespace std;

const int vertextNum = 6;
int adjacencyMatrix[vertextNum][vertextNum];
bool visited[vertextNum];

void DFS(int);

int main()
{
    // initial adjacencyMatrix
    for (int i = 0; i < vertextNum; i++)
        for (int j = 0; j < vertextNum; j++)
            cin >> adjacencyMatrix[i][j];

    //initial visited
    for (int i = 0; i < vertextNum; i++)
        visited[i] = false;

    //start point
    int startPoint = 0;
    cout << startPoint << endl;
    visited[startPoint] = true;
    DFS(startPoint);
}

void DFS(int i) {
    for (int j = 0; j < vertextNum; j++)
        if (adjacencyMatrix[i][j] && !visited[j]) {
            visited[j] = true;
            cout << j << endl;
            DFS(j);
        }
}
