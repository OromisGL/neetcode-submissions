class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> pos;

        for (int i = 0; i < nums.size(); i++){
            pos[nums[i]] = i;
        }

        return pos.contains(target) ? pos[target] : -1;
    }
};
