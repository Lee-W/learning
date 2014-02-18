#include <iostream>
#include <algorithm>
using namespace std;

const int vertextNum = 6;
int adjacencyMatrix[vertextNum][vertextNum];
bool visited[vertextNum];

void DFS(int);

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
    cout<<0<<endl;
    visited[0] = true;
    DFS(0);
}


void DFS(int i)
{
    for (int j = 0; j < vertextNum; j++)
        if (adjacencyMatrix[i][j] && !visited[j]) {
            visited[j] = true;
            cout<<j<<endl;
            DFS(j);
        }
}
