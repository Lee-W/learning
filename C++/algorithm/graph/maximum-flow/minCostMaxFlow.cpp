#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

#define maxN 105
#define maxM 5005
#define INF INT_MAX/10

vector<int> edge[maxN];

int cost[maxN][maxN], capacity[maxN][maxN];
int flow[maxN][maxN], dis[maxN];
int pre[maxN];

void init(int);
void addEdge(int, int, int, int);
int MCMF(int , int, int, int);
bool SPFA(int, int, int);

int main()
{
    int n, m;
    int point1, point2, cap, co;

    while(scanf("%d%d", &n, &m) == 2) {
        init(n);
        while(m--) {
            scanf("%d%d%d%d", &point1, &point2, &cap, &co);
            addEdge(point1, point2, cap, co);
        }

        int minCost = MCMF(0, n, n+1, 0);
        if (minCost != -1)
            printf("%d\n", minCost);
        else
            printf("Impossible.\n");
    }
}


void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
}

void addEdge(int x, int y, int cap, int co) {
    edge[x].push_back(y);
    edge[y].push_back(x);
    capacity[x][y] = cap;
    cost[x][y] = co;
}

int MCMF(int source, int sink, int vertexNum, int leastFlow) {
    int maxFlow = 0, minCost = 0;
    while(SPFA(source, sink, vertexNum)) {
        int f = INF;

        for (int i = sink; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                f = min(f, flow[i][pre[i]]);
            else if (capacity[pre[i]][i] - flow[pre[i]][i] > 0)
                f = min(f, capacity[pre[i]][i] - flow[pre[i]][i]); 
        }

        for (int i = sink; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                flow[i][pre[i]] -= f;
            else if (capacity[pre[i]][i] - flow[pre[i]][i] > 0)
                flow[pre[i]][i] += f;
        }

        maxFlow += f;
        minCost += f * dis[sink];
    }
    if (maxFlow < leastFlow)
        return -1;
    return minCost;
}

bool SPFA(int source, int sink, int vertexNum) {
    bool inqueue[vertexNum];
    queue<int>q;
    for (int i = source; i <= vertexNum; i++)
        dis[i] = INF;

    memset(inqueue, false, sizeof(inqueue));
    memset(pre, -1, sizeof(pre));

    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    int current, next;
    while(!q.empty()) {
        current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < (int)edge[current].size(); i++) {
            next = edge[current][i];

            if (flow[next][current] > 0 && dis[current] - cost[next][current] < dis[next]) {
                dis[next] = dis[current] - cost[next][current];
                pre[next] = current;

                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            } else if (capacity[current][next] - flow[current][next] > 0 && dis[current] + cost[current][next] < dis[next]) {
                dis[next] = dis[current] + cost[current][next];
                pre[next] = current;

                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            }
        }
    }

    if (pre[sink] == -1)
        return false;
    else
        return true;
}
