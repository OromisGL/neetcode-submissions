class Solution {
public:

    struct TrieNode {
        TrieNode* children[26] = {};
        bool leave = false;
    };

    TrieNode* root = nullptr;

    void fill(const vector<string>& dict) {
        for (const string& w : dict) {
            TrieNode* curr = root;
            for (char c : w) {
                if (!curr->children[c - 'a']) {
                    TrieNode* tmp = new TrieNode();
                    curr->children[c - 'a'] = tmp;
                }
                curr = curr->children[c - 'a'];
            }
            curr->leave = true;
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        root = new TrieNode();

        fill(wordDict);

        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) continue;
            TrieNode* curr = root;
            for (int j = i; j < s.size(); j++) {
                int idx = s[j] - 'a';
                if (!curr->children[idx]) break;

                curr = curr->children[idx];
                if (curr->leave) dp[j + 1] = true;
            }
        }

        return dp[s.size()];

    }
};
