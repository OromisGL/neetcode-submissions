class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> seen(nums.size() + 1, false);

        for (int num : nums) {
            if (seen[num]) return num;
            seen[num] = true;
        }

        return 0;
    }
};
