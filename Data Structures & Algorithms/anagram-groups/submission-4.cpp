class Solution {
public:
    string hash(const string& s){
        string key;
        vector<int> v(128 * 3);
        key.reserve(128*3);
        for (unsigned char c : s) v[c]++;
        for (int c : v){
            key += '#';
            key += to_string(c);
        }
        return key;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ret;
        if (n == 0) return ret;
        unordered_map<string, vector<string>> group;

        for (const auto& s : strs){
            group[hash(s)].push_back(s);
        }

        for (const auto& [s,v] : group){
            ret.push_back(move(v));
        }

        return ret;
    }
};
