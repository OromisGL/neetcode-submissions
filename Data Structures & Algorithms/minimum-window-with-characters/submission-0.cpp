class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return "";

        unordered_map<char, int> freq;
        unordered_map<char, int> winfreq;

        for (const char& c : t) freq[c]++;

        int need = freq.size();
        int bestleft = 0;
        int have = 0;
        int best = INT_MAX;

        for (int left = 0, right = 0; right < n; right++){
            char c = s[right];
            winfreq[c]++;

            if (freq.count(c) && winfreq[c] == freq[c]) have++;

            while (have == need) {
                int len = right - left + 1;
                if (len < best) {
                    best = len;
                    bestleft = left;
                } 
                char d = s[left++];
                winfreq[d]--;
                if (freq.count(d) && winfreq[d] < freq[d]) have--;

            }
        }

        return best == INT_MAX ? "" : s.substr(bestleft, best);

    }
};
