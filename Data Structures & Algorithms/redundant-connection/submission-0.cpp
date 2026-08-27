class Solution {
public:

    bool bfs_path(int start, int end, int n, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int curr = q.front(); 
            q.pop();

            if (curr == end) return true;

            for (int i : adj[curr]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> res;

        for (const auto& e : edges) {
            if (!adj[e[1]].empty() && !adj[e[0]].empty() && bfs_path(e[0],e[1],n,adj)) return e;
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        return res;
    }
};
