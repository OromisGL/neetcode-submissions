class Solution {
public:
    unordered_map<char, vector<string>> wordMap;
    vector<vector<char>> b;
    struct TreeNode {
        TreeNode* children[26] = {};
        string w = "";
    };

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    TreeNode* root = nullptr;

    void find(TreeNode* node, int y, int x, vector<string>& res) {
        if (!node) return;
        if (!node->w.empty()) {
            res.push_back(node->w);
            node->w = "";
        }

        char tmp = b[y][x];
        b[y][x] = '#';

        for (const auto& d : dir) {
            int dy = y + d[0], dx = x + d[1];

            if (dy >= 0 && dx >= 0 && dy < b.size() && dx < b[0].size() && b[dy][dx] != '#') {
                find(node->children[b[dy][dx] - 'a'], dy,dx,res);
            }
        }
        b[y][x] = tmp;
    }

    void fill(const vector<string>& words) {
        
        for (const string& w : words) {
            TreeNode* curr = root;
            for (const char& c : w) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    TreeNode* tmp = new TreeNode();
                    curr->children[idx] = tmp;
                }
                curr = curr->children[idx];
            }
            curr->w = w;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        root = new TreeNode();

        fill(words);
        b = board;

        vector<string> res;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                find(root->children[b[y][x] - 'a'], y, x, res);
            }
        }

        return res;
    }
};
