/*
    complexity :
        adjacency list : O(V*E)
        adjacency matrix : O(V^2)

*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int vertextNum = 6;

int adjacencyMatrix[vertextNum][vertextNum];
bool visited[vertextNum];

void BFS(int);

main()
{
    // initial adjacencyMatrix
    for (int i = 0; i < vertextNum; i++)
        for (int j = 0; j < vertextNum; j++)
            cin>>adjacencyMatrix[i][j];

    //initial visited
    for (int i = 0; i < vertextNum; i++)
        visited[i] = false;

    //start point
    BFS(0);
}

void BFS(int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    cout << i << endl;

    while(!q.empty()) {
        int start = q.front();
        q.pop();
        for (int j = 0; j < vertextNum; j++)
            if (adjacencyMatrix[start][j] && !visited[j]) {
                q.push(j);
                visited[j] = true;
                cout << j << endl;
            }
    }
}
