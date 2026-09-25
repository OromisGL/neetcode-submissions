class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int dx = find(x);
        int dy = find(y);
        if (dx == dy) return false;
        if (size[dx] < size[dy]) swap(dx, dy);
        parent[dy] = dx;
        size[dx] += size[dy];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 0;

        vector<tuple<int,int,int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                edges.push_back({abs((x1-x2))+abs((y1-y2)), i, j});
            }
        }

        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return get<0>(a) < get<0>(b); });

        for (int i = 0; i < edges.size(); i++) {
            const auto [c, u, v] = edges[i];
            parent[u] = u;
            parent[v] = v;
            size[u] = 1;
            size[v] = 1;
        }
        int total = 0;

        for (int i = 0; i < edges.size(); i++) {
            const auto [c, u, v] = edges[i];
            if (unite(u,v)) total += c;
        }
    
        return total;
    }
};
