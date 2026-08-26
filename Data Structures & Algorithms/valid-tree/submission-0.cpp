class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        unordered_set<int> vis;
        queue<int> q;


        for (const auto& e : edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        q.push(0);
        vis.insert(0);

        while (!q.empty()) {
            int n = q.front();
            q.pop();

            for (int i : adj[n]){
                if (!vis.contains(i)) {
                    q.push(i);
                    vis.insert(i);
                }
            }
        }

        return vis.size() == n;

    }
};
