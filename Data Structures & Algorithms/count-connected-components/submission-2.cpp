class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int count = 0;
        vector<vector<int>> adj(n);
        queue<int> q;
        unordered_set<int> vis;

        for (const auto& e : edges) {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }


        for (int j = 0; j < n; j++){
            if (vis.contains(j)) continue;
            count++;
            q.push(j);
            vis.insert(j);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int i : adj[curr]) {
                    if (!vis.contains(i)) {
                        vis.insert(i);
                        q.push(i);
                    }
                }
            }
        }

        return count;

    }
};
