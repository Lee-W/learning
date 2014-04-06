//for adjacency list

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX/2
#define maxVertexNum 100
#define maxEdgeNum 10000

struct edge {
    int destination;
    int cost;
};

vector<edge> e[maxEdgeNum];
int dis[maxVertexNum];

void SPFA(int vertexNum, int source) {
    queue<int> q;
    bool inqueue[vertexNum];
    for (int i = 0; i <vertexNum; i++) {
        dis[i] = INF;
        inqueue[i] = false;
    }
    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    while(!q.empty()) {
        int current = q.front();
        inqueue[current] = false;
        q.pop();
        for (int i = 0; i < e[source].size(); i++) {
            int destination = e[source][i].destination;
            int cost = e[source][i].cost;
            if (dis[current] + cost < dis[destination]) {
                dis[destination] = dis[current] + cost;
                if (!inqueue[destination]) {
                    q.push(destination);
                    inqueue[destination]  = true;
                }
            }
        }
    }
}

main()
{
    int vertexNum, edgeNum;
    int source, destination, cost;

    cin >> vertexNum >> edgeNum;
    for (int i = 0; i < edgeNum; i++) {
        cin >> source >> destination >> cost;
        edge tmp;
        tmp.destination = destination;
        tmp.cost = cost;
        e[source].push_back(tmp);
        //e[destination].push_back(tmp);    //for bi-direction graph
    }
    SPFA(vertexNum, 0);
}
