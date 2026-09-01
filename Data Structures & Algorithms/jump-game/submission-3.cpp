class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        int maxre = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxre = max(maxre, i + nums[i]);
            if (i + 1 > maxre) return false;
            if (maxre >= nums.size() - 1) return true;
        }
        return false;
    }
};
