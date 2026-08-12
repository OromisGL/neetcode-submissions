class Solution {
public:  

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return {{}};
        unordered_map<string, vector<string>> group;

        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            group[s].push_back(strs[i]);
        }

        vector<vector<string>> ret;
        for (const auto& val : group) {
            ret.push_back(move(val.second));
        }

        return ret;
    }
};
