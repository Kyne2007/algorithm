#include <iostream>
#include <algorithm>
#include <random>
#include "sort.h"
using namespace std;

bool check(int a[], int n)
{
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

int main(int argc, char *argv[])
{
    random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<int> rnum(1, 500);

    for (int i = 0; i <= 4442; ++i) {
        int n = rnum(e);

        auto ta = shared_ptr<int>(new int[n], [](int *p) {delete [] p;});
        auto a = ta.get();
        
        for (int j = 0; j < n; ++j) {
            a[j] = rnum(e);
        }

        //test sort 
        /* quick_sort(a, 0, n - 1); */
        /* heap_sort(a, n); */
        /* counting_sort(a, n, 500); */
        radix_sort(a, n, 3);

        if (check(a, n)) {
            cout << "case#" << i << " success" << endl;
        } else {
            cout << "case#" << i <<" failed" << endl;
            return 0;
        }
    }

    return 0;
}
