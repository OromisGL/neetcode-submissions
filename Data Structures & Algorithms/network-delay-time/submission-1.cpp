class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // cost, node
        vector<int> deg(n + 1, INT_MAX);

        for (const auto& t : times) {
            adj[t[0]].push_back({t[2], t[1]});
        }

        deg[k] = 0;
        q.push({0, k});

        while (!q.empty()) {
            int sz = q.size(); 
            while (sz--) {
                auto [cost, node] = q.top();
                q.pop(); 

                for (auto& [nc, nn] : adj[node]) {
                    if (cost + nc < deg[nn]) {
                        deg[nn] = cost + nc;
                        q.push({cost + nc, nn});
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
