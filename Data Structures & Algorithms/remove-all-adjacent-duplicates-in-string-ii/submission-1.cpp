class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string res;
        for (const char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }

        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++) res += st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};