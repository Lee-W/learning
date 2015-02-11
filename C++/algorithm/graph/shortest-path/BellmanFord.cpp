//for discrete edge structure

#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX/2
#define maxVertexNum 100
#define maxEdgeNum 10000

struct edge {
    int source;
    int destination;
    int cost;
};

edge e[maxEdgeNum];
int dis[maxVertexNum];

void relax(int source, int destination, int cost) {
    if (dis[source] + cost < dis[destination])
        dis[destination] = dis[source] + cost;
}

void BellmanFord(int vertexNum, int edgeNum, int source) {
    for (int i = 0; i < vertexNum; i++)
        dis[i] = INF;

    for (int i = 0; i < vertexNum - 1; i++)
        for (int j = 0; j < edgeNum; j++)
            relax(e[j].source, e[j].destination, e[j].cost);

    /*
       bool existNegativeCycle = false;
       for (int j = 0; j < edgeNum; j++)
            if (dis[source] + cost < dis[destination]) {
                existNegativeCycle = true;
                break;
            }
    */
}

int main()
{
    int vertexNum, edgeNum;

    cin >> vertexNum >> edgeNum;
    for (int i = 0; i < edgeNum; i++)
        cin >> e[i].source >> e[i].destination >> e[i].cost;
    BellmanFord(vertexNum, edgeNum, 0);
}
