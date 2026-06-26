class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int n = s.size();
        int best = 0;

        for (int right = 0, left = 0; right < n; right++){
            while (seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            best = max(best, right - left + 1);
        }

        return best;
    }
};
