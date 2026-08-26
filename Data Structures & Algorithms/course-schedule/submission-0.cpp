class Solution {
public:
    //[[0,1],
    // [1,0]]
    bool canFinish(int num, vector<vector<int>>& p) {
        
        int m = p.size();
        if (m == 0) return true;

        int n = p[0].size();

        vector<vector<int>> adj(num);
        vector<int> degree(num, 0);
        queue<int> q;

        for (const auto& d : p) {
            adj[d[1]].push_back(d[0]);
            degree[d[0]]++;
        }

        for (int i = 0; i < num; i++) {
            if (degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            num--;
            for (int i : adj[curr]) {
                degree[i]--;
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return num == 0;

    }
};
