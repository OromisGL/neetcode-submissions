class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);
        }

        return dp[n - 1];
    }
};
