#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 100

int parent[maxN], ranking[maxN];

void initSet(int n) {
    for (int i = 0; i < maxN; i++) {
        parent[i] = i;
        ranking[i] = 0;
    }
}

void unionSet(int px, int py) {
    if (ranking[px] > ranking[py])
        parent[py] = parent[px];
    else {
        parent[px] = parent[py];
        if (parent[px] == parent[py])
            parent[py]++;
    }
}

int findSet(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = findSet(parent[x]);
}

int main()
{
    int x, y;
    while(cin >> x >> y) {
        x = findSet(x);
        y = findSet(y);
        if (x != y)
            unionSet(x,y);
    }
}
