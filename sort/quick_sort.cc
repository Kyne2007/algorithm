#include "sort.h"
#include <algorithm>

int partition(int a[], int f, int b)
{
    int x = a[b];

    int i = f - 1;

    for (int j = f; j < b; ++j) {
        if (a[j] <= x)
            std::swap(a[++i], a[j]);
    }

    std::swap(a[++i], a[b]);

    return i;
}

void quick_sort(int a[], int f, int b)
{
    if (f < b) {
        int m = partition(a, f, b);
        quick_sort(a, f, m - 1);
        quick_sort(a, m + 1, b);
    }
}

