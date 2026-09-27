class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for (const auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }

        for (auto& [k, v] : adj) {
            sort(v.rbegin(), v.rend());
        }

        vector<string> res;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string curr = st.top();
            if (!adj[curr].empty()) {
                string next = adj[curr].back();
                adj[curr].pop_back();
                st.push(next);
            } else {
                res.push_back(curr);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
