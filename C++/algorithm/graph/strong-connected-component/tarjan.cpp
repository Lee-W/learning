#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

#define maxN 2005

vector<int> edge[maxN];
int dfn[maxN], low[maxN];
bool visited[maxN], inStack[maxN];
stack<int> s;
int num, counter;
int SCC[maxN];

void init(int);
void tarjan(int);

int main()
{
    int vertextNum, edgeNum;
    int u, v;
    while(scanf("%d%d", &vertextNum, &edgeNum) && vertextNum) {
        init(vertextNum);
        while(edgeNum--) {
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
        }

        for (int i = 1; i <= vertextNum; i++)
            if (!visited[i])
                tarjan(i);

        for (int i = 1; i <= vertextNum; i++)
            printf("%d ", SCC[i]);
        printf("\n");
    }
}

void init(int n) {
    for (int i = 1; i <= n; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(visited, false, sizeof(visited));
    memset(inStack, false, sizeof(inStack));
    while(!s.empty())
        s.pop();
    num = 0;
    counter = 0;
}

void tarjan(int current) {
    dfn[current] = low[current] = counter++;

    s.push(current);
    inStack[current] = true;
    visited[current] = true;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            tarjan(next);
            low[current] = min(low[current], low[next]);
        } else if (inStack[next])
            low[current] = min(low[current], dfn[next]);
    }

    if (dfn[current] == low[current]) {
        num++;
        SCC[current]= num;

        int next = 0;
        while(current != next) {
            SCC[next] = num;
            next = s.top();
            inStack[next] = false;
            s.pop();
        }
    }
}
