class Solution {
public:

    unordered_map<char, vector<char>> keys = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
    };

    void backtrack(int i, string& digits, unordered_map<char, vector<char>>& keys, vector<string>& result, string& comb) {
        if (i == digits.size() || comb.size() == digits.size()) {
            result.push_back(comb);
            return;
        }

        for (const char& c : keys[digits[i]]) {
            comb += c;
            backtrack(i + 1, digits, keys, result, comb);
            comb.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> result;
        string comb;

        backtrack(0, digits, keys, result, comb);

        return result;

    }
};











