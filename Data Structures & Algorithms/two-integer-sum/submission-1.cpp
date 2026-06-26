class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mapp;

        for (int i = 0; i < n; i++){
            mapp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++){
            int diff = target - nums[i];
            if (mapp.contains(diff) && mapp[diff] != i){
                return {i, mapp[diff]};
            }
        }

    }
};
