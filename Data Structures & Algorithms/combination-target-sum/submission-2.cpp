class Solution {
public:

    void backtrack(int i, int n, vector<int>& nums, vector<vector<int>>& result, vector<int>& comb) {

        if (n == 0) {
            result.push_back(comb);
            return;
        } else if (i == nums.size() || n < 0) return;

        comb.push_back(nums[i]);
        backtrack(i, n - nums[i], nums, result, comb);
        comb.pop_back();
        backtrack(i + 1, n, nums, result, comb);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        backtrack(0, target, nums, result, comb);

        return result;
    }
};
