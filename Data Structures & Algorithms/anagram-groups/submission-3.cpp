class Solution {
public:
    string hash(const string& s) {
        string key;
        vector<int> v(128);
        key.reserve(128*3);
        for (unsigned char c : s) v[c]++;
        for (int i = 0; i < 128; i++){
            key += '#';
            key += to_string(v[i]);
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ann;
        vector<vector<string>> ret;

        for (const auto& s : strs){
            ann[hash(s)].push_back(s);
        }

        for (const auto& [s, v] : ann) {
            ret.push_back(move(v));
        }

        return ret;
    }
};
