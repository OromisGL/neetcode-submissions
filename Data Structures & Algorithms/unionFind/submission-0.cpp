class UnionFind {
public:

    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    int comp = 0;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        comp = n;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int dx = find(x);
        int dy = find(y);

        if (dx == dy) return false;
        if (size[dx] < size[dy]) swap(dx, dy);

        parent[dy] = dx;
        size[dx] += size[dy];
        comp--;
        return true;
    }

    int getNumComponents() {
        return comp;
    }
};
