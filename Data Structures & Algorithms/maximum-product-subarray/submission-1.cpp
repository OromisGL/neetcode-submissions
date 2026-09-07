class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int currmax = 1;
        int currmin = 1;
        int best = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                swap(currmax, currmin);
            }

            currmax = max(nums[i], currmax * nums[i]);
            currmin = min(nums[i], currmin * nums[i]);

            best = max(currmax, best);

        }

        return best;
    }
};
