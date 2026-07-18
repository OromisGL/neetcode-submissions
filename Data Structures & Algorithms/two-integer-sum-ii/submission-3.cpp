class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {

        int n = num.size();

        int left = 0;
        int right = n -1;

        while (left < right) {
            
            if (num[left] + num[right] > target) {
                right--;
            } else if (num[left] + num[right] < target){
                left++;
            } else {
                return {left + 1, right + 1};
            }
            
        }
        return {};
    }
};
