class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int mind = INT_MAX;

        while (left <= right) {
            int mid = left + ((right - left) / 2);
            int select = nums[mid];
            mind = min(mind, select);
            if (select <= nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return mind;
    }
};
