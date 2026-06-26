class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ret;
        if (n == 0) return ret;
        unordered_map<string, vector<string>> group;

        for (const auto& s : strs){
            string t = s;
            sort(t.begin(),t.end());
            group[t].push_back(s);
        }

        for (const auto& v : group){
            ret.push_back(move(v.second));
        }

        return ret;
    }
};
