#include "sort.h"
#include <cstring>

void merge_sort(int a[], int copy[], int start, int end)
{
    if (start == end) {
        copy[start] = a[start];
        return ;
    }

    int len = (end - start) / 2;
    merge_sort(copy, a, start, start + len);
    merge_sort(copy, a, start + len + 1, end);

    int i = start + len;
    int j = end;
    int index_copy = end;

    while (i >= start && j >= start + len + 1) {
        if (a[i] > a[j])
            copy[index_copy--] = a[i--];
        else
            copy[index_copy--] = a[j--];
    }

    for (; i >= start; i--)
            copy[index_copy--] = a[i--];
    for (; j >= start + len + 1; j--)
            copy[index_copy--] = a[j--];
}

void merge_sort(int a[], int n)
{
    if (a == nullptr || n <= 0)
        return ;

    int *copy = new int[n];
    memcpy(copy, a, sizeof(int) * n);

    merge_sort(copy, a, 0, n - 1);

    delete [] copy;
}

