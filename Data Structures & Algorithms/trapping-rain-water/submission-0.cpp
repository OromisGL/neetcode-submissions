class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> prefix(n, 0);
        prefix[0] = h[0];
        for (int i = 1; i < n; i++){
            prefix[i] = max(h[i], prefix[i - 1]);
        }

        vector<int> suffix(n, 0);
        suffix[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(h[i], suffix[i + 1]);
        }

        int maxvol = 0;

        for (int i = 0; i < n; i++) {
            int vol = min(suffix[i], prefix[i]) - h[i];

            maxvol += vol;
        }

        return maxvol;
    }   
};
