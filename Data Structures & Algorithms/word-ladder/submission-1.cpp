class Solution {
public:

    bool common(string& s, string& j) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != j[i]) n++;
            if (n > 1) return false;
        }
        return n == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        int n = w.size();
        int m = beginWord.size();
        int end = -1;

        vector<vector<int>> adj(n);
        vector<int> seen(n + 1);
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++) {
            if (w[i] == endWord) end = i;
            if (common(beginWord, w[i])) {
                q.push({i, 2});
                seen[i] = 1;
                }
            for (int j = i + 1; j < n; j++){
                if(common(w[i],w[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if (end == -1) return 0;

        while (!q.empty()) {
            int curr = q.front().first;
            int count = q.front().second;
            q.pop();
            if (curr == end) return count;

            for (int i : adj[curr]) {
                if (!seen[i]) {
                    q.push({i, count + 1});
                    seen[i] = 1;
                }
            }
        }

        return 0;
    }
};
