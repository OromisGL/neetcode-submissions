class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> deg(n + 1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n + 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (const auto& v : times) {
            adj[v[0]].push_back({v[2], v[1]});
        }

        deg[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int sz = pq.size();
            while (sz--) {
                auto [cost, node] = pq.top();
                pq.pop();
                for (const auto& [nc, neig] : adj[node]) {
                    if (cost + nc < deg[neig]) {
                        pq.push({cost + nc, neig});
                        deg[neig] = cost + nc;
                    }
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == INT_MAX) return -1;
            maxTime = max(deg[i], maxTime);
        }
        return maxTime;
    }
};
