class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int best = 0, left = 0, maxfreq = 0;
        vector<int> freq(26, 0);

        for (int right = 0; right < n; right++){
            int idx = s[right] - 'A';
            freq[idx]++;
            maxfreq = max(maxfreq, freq[idx]);
            while ((right - left + 1) - maxfreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }

        return best;
    }
};
