#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

#define maxN 105
#define maxM 10005
#define INF INT_MAX/5

int flowCapacity[maxN][maxN], flow[maxN][maxN], residual[maxN][maxN];
bool visited[maxN];
int path[maxN], bottleneck[maxN];

void init();
int EdmondsKarp(int, int, int);
int BFS(int, int, int);

int main()
{
    int n, source, sink, conntectionNum;
    int start, end, cap;

    scanf("%d", &n);
    scanf("%d%d%d", &source, &sink, &conntectionNum);
    memset(flowCapacity, 0, sizeof(flowCapacity));

    while(conntectionNum--) {
        scanf("%d%d%d", &start, &end, &cap);
        flowCapacity[start][end] = cap;
    }
    init();
    printf("%d\n", EdmondsKarp(source, sink, n+2));
}


void init() {
    memset(flow, 0, sizeof(flow));
    memcpy(residual, flowCapacity, sizeof(flowCapacity));
    memset(path, -1, sizeof(path));
    memset(bottleneck, 0, sizeof(bottleneck));
}

int EdmondsKarp(int s, int t, int n) {
    int maxFlow = 0;
    int currentFlow;
    while ((currentFlow = BFS(s, t ,n) != 0)) {
        int pre = path[t];
        int cur = t;
        while(pre != cur) {
            flow[pre][cur] = flow[pre][cur] + currentFlow;
            flow[cur][pre] = -flow[pre][cur];
            residual[pre][cur] = flowCapacity[pre][cur] - flow[pre][cur];
            residual[cur][pre] = flowCapacity[cur][pre] - flow[cur][pre];
            cur = pre;
            pre = path[cur];
        }
        maxFlow += currentFlow;
    }
    return maxFlow;
}

int BFS(int s, int t, int n) {
    memset(visited, false, sizeof(visited));

    queue<int> q;
    visited[s] = true;
    path[s] = s;
    bottleneck[s] = INF;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
            if (!visited[i] && residual[cur][i] > 0) {
                visited[i] = true;
                path[i] = cur;
                bottleneck[i] = min(bottleneck[cur], residual[cur][i]);
                q.push(i);

                if (i == t)
                    return bottleneck[t];
            }
    }
    return 0;
}
