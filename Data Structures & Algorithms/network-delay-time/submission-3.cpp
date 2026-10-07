class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int dx = find(x);
        int dy = find(y);
        if (dx == dy) return false;
        if (size[dx] < size[dy]) swap(dx,dy);
        parent[dy] = dx;
        size[dx] += size[dy];
        return true;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> deg(n + 1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n + 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (const auto& v : times) {
            adj[v[0]].push_back({v[2], v[1]});
        }

        pq.push({0, k});
        deg[k] = 0;

        while (!pq.empty()) {
            int sz = pq.size();
            while (sz--) {
                auto [cost,node] = pq.top();
                pq.pop();

                for (const auto& [nc, nn] : adj[node]) {
                    if (nc + cost < deg[nn]) {
                        deg[nn] = nc+cost;
                        pq.push({cost+nc,nn});
                    }
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == INT_MAX) return -1;
            maxTime = max(maxTime, deg[i]);
        }
        return maxTime;
    }
};
