class Solution {
public:

    void bt_dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& st, int remain, int index) {
        if (remain == 0) {
            result.push_back(st);
            return;
        }
        if (index == nums.size() || remain < 0) {
            return;
        }

        st.push_back(nums[index]);
        bt_dfs(result, nums, st, remain - nums[index], index);

        st.pop_back();
        bt_dfs(result, nums, st, remain, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> st;

        bt_dfs(result, nums, st, target, 0);

        return result;
    }
};
