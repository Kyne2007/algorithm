#include "sort.h"
#include <algorithm>

inline int left(int i) {return i << 1;}
inline int right(int i) {return i << 1 | 1;}

void max_heapify(int a[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= n && a[l - 1] > a[i - 1])
        largest = l;
    if (r <= n && a[r - 1] > a[largest - 1])
        largest = r;

    if (largest != i) {
        std::swap(a[largest - 1], a[i - 1]);
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int a[], int n)
{
    for (int i = n / 2; i >= 1; --i)
        max_heapify(a, n, i);
}

void heap_sort(int a[], int n)
{
    build_max_heap(a, n);
    for (int i = n; i >= 2; --i) {
        std::swap(a[0], a[i - 1]);
        max_heapify(a, i - 1, 1);
    }
}

