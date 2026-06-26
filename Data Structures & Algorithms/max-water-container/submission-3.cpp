class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int best = INT_MIN;

        int left = 0; 
        int right = n - 1;

        while(left < right) {
            int vol = min(heights[left], heights[right]) * (right - left);
            best = max(vol, best);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return best;
    }
};
