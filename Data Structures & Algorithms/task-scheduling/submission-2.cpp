class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> freq(26,0);
        int countmax = 0;
        for (char& c : tasks) {
            freq[c - 'A']++;
        }

        int maxfreq = *max_element(freq.begin(), freq.end());

        for (int i : freq) {
            if (i == maxfreq) {
                countmax++;
            }
        }
        return max(m, (maxfreq - 1) * (n + 1) + countmax);
    }
};
