class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.size() == 1) return {1};
        vector<int> pos(26, 0);

        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'] = i;
        }

        vector<int> res;
        int end = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, pos[s[i] - 'a']);
            if (i == end) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
