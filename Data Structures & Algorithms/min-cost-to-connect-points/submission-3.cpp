class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int find(int x ) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int dx = find(x);
        int dy = find(y);

        if(dx == dy) return false;
        if(dx < dy) swap(dx, dy);

        parent[dy] = dx;
        size[dx] += size[dy];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<tuple<int,int,int>> nodes; // cost, u, v

        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                nodes.push_back({abs(x2-x1)+abs(y2-y1), i, j});
            }
        }

        sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });
        for (const auto& node : nodes) {
            auto [c, u, v] = node;
            parent[u] = u;
            parent[v] = v;
            size[v] = 1;
            size[u] = 1;
        }
        int total = 0;
        for (const auto& node : nodes) {
            auto [c, u, v] = node;
            if (unite(u, v)) total += c;
        }
        return total;
    }
};
