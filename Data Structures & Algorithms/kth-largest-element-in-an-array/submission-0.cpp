class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for (int i : nums) {
            q.emplace(i);
        }

        while (!q.empty()) {
            if (k == 1) break;
            q.pop();
            k--;
        }
        return q.top();
    }
};
