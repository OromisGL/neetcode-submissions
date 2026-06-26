class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0, best = 0, maxfreq = 0;
        vector<int> freq(26, 0);
        
        for (int right = 0; right < s.size(); right++){
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
