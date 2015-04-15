#include "sort.h"

void counting_sort(int a[], int n, int k)
{
    int *c = new int[k + 1]{0};
    
    for (int i = 0; i < n; ++i)
        ++c[a[i]];

    for (int i = 1; i <= k; ++i)
        c[i] += c[i - 1];

    int *b = new int[n];
    //这样循环可以保证是稳定排序
    for (int i = n - 1; i >= 0; --i) {
        b[c[a[i]] - 1] = a[i];
        --c[a[i]];
    }

    for (int i = 0; i < n; ++i)
        a[i] = b[i];
}

