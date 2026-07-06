class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        int vol = 0;

        while (left < right) {
            vol = max(vol, min(heights[left], heights[right]) * (right - left));
            
            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }
        }

        return vol;
    }
};
