#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 105


vector<int>edge[MAX];

int llink[MAX], rlink[MAX];
bool visited[MAX];

void initEdge(int,int);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    int nL, nR;

    while(scanf("%d%d", &n, &m) == 2) {
        initEdge(nL, nR);
        printf("%d\n", n - Bipartite(n, m));
    }
}

void initEdge(int n, int m) {
    //initital edge according to input
}

int Bipartite(int nL, int nR) {
    int num = 0;
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));

    for (int i = 1; i <= nL; i++) {
        memset(visited, false, sizeof(visited));
        if (DFS(i))
            num++;
    }
    return num;
}

bool DFS(int current) {
    for (int i = 0; i < edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            visited[next] = true;

            if (!rlink[next] || DFS(rlink[next])) {
                llink[current] = next;
                rlink[next] = current;
                return true;
            }
        }
    }
    return false;
}
