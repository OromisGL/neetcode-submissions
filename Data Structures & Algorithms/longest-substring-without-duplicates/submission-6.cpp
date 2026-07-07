class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return 1;
        unordered_set<char> chars;
        int len = 0;
        int left = 0; 
        int right = 0;        
        
        while (right < s.size()) {
            if (chars.find(s[right]) == chars.end()) {
                chars.insert(s[right]);
                len = max(len, right - left + 1);
                right++;
            } else {
                chars.erase(s[left]);
                left++;
            } 
        }
        len = max(len, right - left);

        return len;
    }
};
