class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();

        vector<int> dist(n, INT_MAX);
        queue<pair<int,int>> q; // {node,cost}
        vector<vector<pair<int,int>>> adj(n);

        for (const auto& v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        dist[src] = 0;
        q.push({src,0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();
                for (auto [neigh, ncost] : adj[node]) {
                    if (cost + ncost < dist[neigh]) {
                        dist[neigh] = cost + ncost;
                        q.push({neigh, ncost + cost});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
