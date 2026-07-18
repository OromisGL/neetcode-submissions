class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int left = 0;
        int right = n -1;
        int maxvol = 0;

        while (left < right) {
            int vol = min(h[left], h[right]) * (right - left);

            maxvol = max(vol, maxvol);
            if (h[left] < h[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxvol;
    }
};
