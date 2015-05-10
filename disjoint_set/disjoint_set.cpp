#include "disjoint_set.h"


void disjoint_set::make_set(int x)
{
    parent[x] = x;
    rank[x] = 0;
}


void disjoint_set::union_set(int x, int y)
{
    int px = find_set(x);
    int py = find_set(y);

    if (px == py)
        return ;

    if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[px] = py;
        if (rank[py] == rank[px])
            rank[py]++;
    }
}

int disjoint_set::find_set(int x)
{
    if (x != parent[x])
        parent[x] = find_set(parent[x]);

    return parent[x];
}

