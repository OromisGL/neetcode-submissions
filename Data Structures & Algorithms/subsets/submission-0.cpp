class Solution {
public:

    void backtrack(int start, vector<int>& perm, vector<vector<int>>& result, vector<int>& nums) {
        result.push_back(perm);

        for (int i = start; i < nums.size(); i++) {
            perm.push_back(nums[i]);
            backtrack(i + 1, perm, result, nums);
            perm.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> perm;

        backtrack(0, perm, result, nums);

        return result;
    }
};
