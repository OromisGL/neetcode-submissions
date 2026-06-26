class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0; 
        int right = n -1;
        int water = INT_MIN;

        while (left < right){
            int container = min(heights[left], heights[right]) * (right - left);
            water = max(container, water);
            if (heights[left] < heights[right])
                left++;
            else 
                right--;
        }

        return water;
    }
};
