class Solution {
public:
    struct Port {
        int nr;
        int cost;
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<Port>> adj(n);
        vector<int> deg(n, INT_MAX);
        queue<Port> q;

        for (const auto& v : flights) {
            adj[v[0]].push_back({v[1],v[2]});
        }

        q.push({src,0});
        deg[src] = 0;
        int stp = 0;

        while (!q.empty() && stp <= k) {
            int sz = q.size();
            while (sz--) {
                Port p = q.front();
                q.pop();

                for (const Port n : adj[p.nr]) {
                    if (n.cost + p.cost < deg[n.nr]) {
                        q.push({n.nr, n.cost + p.cost});
                        deg[n.nr] = n.cost + p.cost;
                    }
                }
            }
            stp++;
        }

        return deg[dst] == INT_MAX ? -1 : deg[dst];

    }
};
