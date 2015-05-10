#include "disjoint_set.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    disjoint_set s(100);

    s.make_set(1);
    s.make_set(2);
    s.make_set(3);
    s.make_set(4);

    s.union_set(1,2);

    cout << s.find_set(1) << endl;
    cout << s.find_set(2) << endl;

    return 0;
}
