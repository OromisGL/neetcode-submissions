class Solution {
public:
    int maxArea(vector<int>& h) {
        int best = INT_MIN;
        int right = h.size() - 1;

        int left = 0;

        while (left < right) {
            int vol = min(h[left], h[right]) * (right - left);

            best = max(best, vol);
            if (h[left] < h[right]){
                left++;
            } else { 
                right--;
            }
        }

        return best;

    }
};
