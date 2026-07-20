class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        int n = h.size();
        if (n == 1) return h[0];

        stack<int> st;
        int maxrect = 0;

        for (int i = 0; i <= n; i++) {
            int currh = (i == n) ? 0 : h[i];
            while (!st.empty() && h[st.top()] >= currh) {
                int height = h[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxrect = max(maxrect, height * w);
            }
            st.push(i);
        }

        return maxrect;
    }
};
