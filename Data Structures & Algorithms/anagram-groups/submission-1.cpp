class Solution {
public:
    string hash(const string& s){
        vector<int> cnt(26,0);
        for (char c : s) cnt[c - 'a']++;

        string key;
        key.reserve(26 * 3);
        for (int x : cnt) {
            key += '#';
            key += to_string(x);
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> annas;
        if (strs.size() == 0) return {};

        for (const string& s : strs) {
            annas[hash(s)].push_back(s);
        }
        vector<vector<string>> out;
        out.reserve(annas.size());
        for (auto& p : annas) {
            out.push_back(move(p.second));
        }

        return out;
        
    }
};
