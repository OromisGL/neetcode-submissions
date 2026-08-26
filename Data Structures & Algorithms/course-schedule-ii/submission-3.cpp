class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& p) {
        vector<int> res;

        vector<vector<int>> adj(num);
        vector<int> degree(num, 0);
        queue<int> q;

        for (const auto& node : p) {
            adj[node[1]].push_back(node[0]);
            degree[node[0]]++;
        }

        for (int i = 0; i < num; i++) {
            if (degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int n = q.front();
            q.pop();

            res.push_back(n);
            for (int i : adj[n]) {
                degree[i]--;
                if (degree[i] == 0) q.push(i);
            }
        }

        if (res.size() == num) return res;
        return {};
    }
};
