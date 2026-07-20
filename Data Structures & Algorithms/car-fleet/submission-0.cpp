class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int, int>> link(n, pair<int,int>(2,0));

        for (int i = 0; i < n; i++) {
            link[i] = {pos[i], speed[i]};
        }
        sort(link.begin(), link.end(), [](const auto& left, const auto& right) {
            return left.first > right.first;
        });

        stack<float> st;

        for (int i = 0; i < n; i++) {
            float time = (float)(target - link[i].first) / (float)link[i].second;
            if (st.empty()) {
                st.push(time);
                continue;
                }
            if (st.top() < time) {
                st.push(time);
            }   
        }

        return st.size();
    }
};
