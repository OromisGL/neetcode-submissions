class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = INT_MIN;

        int left = 0;
        int right = n -1;

        while (left < right) {
            int amount = min(heights[left], heights[right]) * (right - left);
            res = max(res, amount);

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return res;
    }
};
