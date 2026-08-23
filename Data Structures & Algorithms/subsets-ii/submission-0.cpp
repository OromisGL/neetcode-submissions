class Solution {
public:

    void backtrack(int start, vector<int>& comb, vector<vector<int>>& result, vector<int>& nums) {
        result.push_back(comb);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            comb.push_back(nums[i]);
            backtrack(i + 1, comb, result, nums);
            comb.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> comb;

        sort(nums.begin(), nums.end());

        backtrack(0, comb, result, nums);

        return result;
    }
};
