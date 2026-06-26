class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> pos;
        int n = numbers.size();

        for (int i = 0; i < n; i++){
            pos[numbers[i]] = i;
        }

        for (int i = 0; i < n; i++){
            if (pos.contains(target - numbers[i]) && i != pos[target - numbers[i]]){
                return {i + 1, pos[target - numbers[i]] + 1};
            }
        }
        return {};
    }
};
