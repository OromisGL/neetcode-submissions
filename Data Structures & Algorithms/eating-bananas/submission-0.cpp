class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN; 

        for (int i : piles) {
            maxi = max(maxi, i);
        }

        int left = 1; 
        int right = maxi;
        int reslut = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            long long totalh = 0;
            for (int p : piles) {
                totalh += (p + mid - 1) / mid;
            }

            if (totalh <= h) {
                reslut = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return reslut;
    }
};
