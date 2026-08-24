class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() == 1 && s2.size() == 1) return s1[0] == s2[0];
        if (s1.size() > s2.size()) return false;

        vector<int> lett(26, 0);
        vector<int> wCount(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            lett[s1[i] - 'a']++;
            wCount[s2[i] - 'a']++;
        }
        if (lett == wCount) return true;
        for (int i = s1.size(); i < s2.size(); i++) {
            wCount[s2[i] - 'a']++;
            wCount[s2[i - s1.size()] - 'a']--;

            if (wCount == lett) return true;
        }
        return false;
    }
};
