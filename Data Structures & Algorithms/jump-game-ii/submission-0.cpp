class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int end = 0;
        int jumps = 0;
        int far = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(nums[i] + i, far);
            if (i == end) {
                jumps++;
                end = far;
            }
        }

        return jumps;
    }
};
