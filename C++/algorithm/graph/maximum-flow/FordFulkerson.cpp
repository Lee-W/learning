//1-based
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

#define maxN 105
#define INF INT_MAX/5

int capacity[maxN][maxN];
int flow[maxN][maxN];
bool visited[maxN];
int pa[maxN];

int FordFlukerson(int,int,int);
bool DFS(int,int,int);
int findFlow(int,int);

int main()
{
    int n, source, sink, conntectionNum;
    int start, end, cap;

    scanf("%d", &n);
    scanf("%d%d%d", &source, &sink, &conntectionNum);
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    memset(pa, 0, sizeof(pa));
    memset(visited, 0, sizeof(visited));

    while(conntectionNum--) {
        scanf("%d%d%d", &start, &end, &cap);
        capacity[start][end] = cap;
    }

    printf("%d.\n", FordFlukerson(source, sink, n));
}

int FordFlukerson(int s,int t,int n) {
    int maxFlow = 0;

    while(1) {
        memset(visited, 0, sizeof(visited));
        if (!DFS(s,t,n))
            break;
        maxFlow += findFlow(s,t);
    }
    return maxFlow;
}

bool DFS(int current, int sink, int n) {
    visited[current] = true;
    if (current == sink)
        return true;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        if (capacity[current][i] - flow[current][i] > 0 || flow[i][current] > 0) {
            pa[i] = current;
            if (DFS(i, sink, n))
                return true;
        }
    }
        return false;
}

int findFlow(int source, int sink) {
    int pre;
    int f = INF;
    for (int i = sink; i!= source; i = pa[i]) {
        pre = pa[i];

        if (capacity[pre][i] - flow[pre][i] > 0)
            f = std::min(f, capacity[pre][i] - flow[pre][i]);
        else
            f = std::min(f, flow[i][pre]);
    }

    for (int i = sink; i != source; i = pa[i]) {
        pre = pa[i];

        if (capacity[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else
            flow[i][pre] -= f;
    }
    return f;
}
