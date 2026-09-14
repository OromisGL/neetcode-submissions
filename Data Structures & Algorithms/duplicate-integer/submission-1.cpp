class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return false;
        unordered_set<int> seen;

        for (int num : nums) {
            if (!seen.contains(num)) {
                seen.insert(num);
            } else {
                return true;
            }
        }

        return false;
    }
};