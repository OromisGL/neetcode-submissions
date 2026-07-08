class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size(); 
        vector<int> ret(n, 0);
        if (n == 1) return ret;

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && t[i] > t[st.top()]){
                int prev = st.top();
                st.pop();
                ret[prev] = i - prev;
            }
            st.push(i);
        }
        return ret;
    }
};
