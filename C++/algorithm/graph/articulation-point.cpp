#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define maxN 105

vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector<int>articulationPoint;

void init(int);
void DFS(int,int,int);

int main()
{
    int vertexNum, edgeNum;
    int source, destination;
    while (scanf("%d%d", &vertexNum, &edgeNum)) {
        init(vertexNum);
        while(edgeNum--) {
            scanf("%d%d", &source, &destination);
            edge[source].push_back(destination);
        }

        DFS(1, 0, 1);
        for (int i = 0; i < articulationPoint.size(); i++)
            printf("%d\n", articulationPoint[i]);
        printf("\n");
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    articulationPoint.clear();
}

void DFS(int current, int parent, int counter) {
    int child = 0;
    bool isArticulationPoint = false;

    dfn[current] = low[current] = counter++;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];
        if (!dfn[next]) {
            child++;
            DFS(next, current, counter);
            low[current] = min(low[current], low[next]);

            if (low[next] >= dfn[current])
                isArticulationPoint = true;
        } else if (next != parent)
            low[current] = min(low[current], dfn[next]);
    }
    if ((child >= 2 || parent > 0) && isArticulationPoint) {
        articulationPoint.push_back(current);
    }
}
