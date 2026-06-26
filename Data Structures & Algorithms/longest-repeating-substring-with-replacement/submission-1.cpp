class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxfreq = 0, best = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            int idx = s[right] - 'A';
            freq[idx]++;
            maxfreq = max(maxfreq, freq[idx]);

            while ((right - left + 1) - maxfreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            best = max(best, right - left + 1);
        }

        return best;

    }
};
