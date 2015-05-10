#ifndef DISJOINT_H_
#define DISJOINT_H_
#include <vector>

class disjoint_set {
    public:
        disjoint_set(int n) : parent(n, -1), rank(n) {}

        void make_set(int x);
        void union_set(int x, int y);
        int find_set(int x);

    private:
        std::vector<int> parent;
        std::vector<int> rank;
};

#endif
