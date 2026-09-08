class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        if (abs(target) > total || (target + total) % 2 != 0) return 0;
        long long s = (target + total) / 2;

        vector<long long> dp(s + 1, 0);
        dp[0] = 1;

        for (int num : nums){
            for (int i = s; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        return dp[s];

    }
};
