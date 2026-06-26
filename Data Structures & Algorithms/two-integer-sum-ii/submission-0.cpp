class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        unordered_map<int, int> sum;

        for (int i = 0; i < numbers.size(); i++) {
            sum[numbers[i]] = i + 1;
        }

        for (int i = 0; i < numbers.size(); i++){
            int diff = target - numbers[i];
            if (sum.contains(diff) && sum[diff] > i + 1) return {i + 1, sum[diff]};
        }
        return {};
    }
};
