class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> table;

        for (int i = 0; i < n; i++) {
            table[nums[i]] = i;
        }

        for (int i = 0; i < n; i ++){
            int diff = target - nums[i];
            if(table.contains(diff) && i != table[diff]){
                return {i, table[diff]};
            }
        }
    }
};
