class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int n = s.size();
        int left = 0; 
        int best = 0;
        for (int right = 0; right < n; right++){
            while (seen.contains(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            best = max(best, right - left + 1);
        }
        return best;
    }
};
