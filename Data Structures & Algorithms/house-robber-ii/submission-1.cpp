class Solution {
public:

    int find(vector<int>& num, int start, int end) {
        int n = end-start + 1;
        if (n <= 0) return 0;
        if (n == 1) return num[start];

        vector<int> dp(n, 0);
        dp[0] = num[start];
        dp[1] = max(num[start], num[start + 1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], num[start + i] + dp[i - 2]);
        }
        return dp[n - 1];
    }   

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int on = find(nums, 0, n - 2);
        int bn = find(nums, 1, n - 1);

        return max(on,bn);

    }
};
