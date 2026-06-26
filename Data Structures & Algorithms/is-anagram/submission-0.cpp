class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) return false;

        unordered_map<char, int> mapping1;
        unordered_map<char, int> mapping2;

        for (int i = 0; i < n; i++){
            mapping1[s[i]]++;
        }
        for (int i = 0; i < m; i++){
            mapping2[t[i]]++;
        }

        return mapping1 == mapping2;
        
    }   
};
