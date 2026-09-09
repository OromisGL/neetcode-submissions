class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.size() == 1) return {1};
        unordered_map<char, int> lastpos;

        for (int i = 0; i < s.size(); i++) {
            lastpos[s[i]] = i;
        }

        vector<int> res;
        int end = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastpos[s[i]]);
            if (i == end) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
