class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int n = strs.size();
        if (n == 0) return {};
        unordered_map<string, vector<string>> group;

        for (const string& c : strs) {
            string s = c;
            sort(s.begin(),s.end());
            group[s].push_back(c);
        }

        for (const auto& v : group) {
            ret.push_back(move(v.second));
        }

        return ret;
    }
};
