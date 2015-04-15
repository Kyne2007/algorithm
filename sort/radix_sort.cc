#include "sort.h"
#include <iostream>
using namespace std;

//计数排序的修改版，根据权值w所代表的位来进行排序
void counting_sort(int a[], int n, int w)
{
    int k = 10;

    int *c = new int[k + 1]{0};
    
    for (int i = 0; i < n; ++i)
        ++c[a[i] / w % 10];

    for (int i = 1; i <= k; ++i)
        c[i] += c[i - 1];

    int *b = new int[n];
    for (int i = n - 1; i >= 0; --i) {
        b[c[a[i] / w % 10] - 1] = a[i];
        --c[a[i] / w % 10];
    }

    for (int i = 0; i < n; ++i)
        a[i] = b[i];
}

void radix_sort(int a[], int n, int d)
{
    //从低位到高位进行排序，因为高位有更高的权值，当高位相同时才判断低位的大小
    for (int i = 1, w = 1; i <= d; ++i) {
        counting_sort(a, n, w);
        w *= 10;
    }
}

