class Solution {
public:  

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return {{}};
        unordered_map<string, vector<string>> group;
        vector<string> sorted = strs;

        for (string& s : sorted) {
            sort(s.begin(), s.end());
        }

        for (int i = 0; i < n; i++) {
            group[sorted[i]].push_back(strs[i]);
        }

        vector<vector<string>> ret;
        for (const auto& val : group) {
            ret.push_back(move(val.second));
        }

        return ret;
    }
};
