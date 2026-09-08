class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0 && m == 0) return 0.0;

        if (n > m) {
            swap(nums1, nums2);
            return findMedianSortedArrays(nums1, nums2);
        }

        int low = 0;
        int high = n;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minright1 = (i == n) ? INT_MAX : nums1[i];

            int maxleft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minright2 = (j == m) ? INT_MAX : nums2[j];

            if (maxLeft1 <= minright2 && maxleft2 <= minright1) {
                if ((n + m) % 2 == 1) {
                    return (double)max(maxLeft1, maxleft2);
                } else {
                    return (max(maxLeft1, maxleft2) + min(minright1, minright2)) / 2.0;
                }
            } else if (maxLeft1 > minright2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        return 0.0;

    }
};
