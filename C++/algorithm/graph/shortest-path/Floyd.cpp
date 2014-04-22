//0-based

#include <cstdio>

#define maxN 100

int dis[maxN][maxN];

void Floyd(int n) {
    for (int mid = 0; mid < n; mid++)
        for (int source = 0; source < n; source++)
            for (int destination = 0; destination < n; destination++)
                if (dis[source][destination] < dis[source][mid] + dis[mid][destination])
                    dis[source][destination] = dis[source][mid] + dis[mid][destination];
}

main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dis[i][j]);
    Floyd(n);
}
