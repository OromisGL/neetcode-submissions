class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n -1;
        while (left <= right) {
            int mid = left + (right - left);

            if (nums[mid] == target) return mid;

            if (target < nums[mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        return -1;
    }
};
