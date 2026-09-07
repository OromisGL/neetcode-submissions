class Solution {
public:
    vector<vector<char>> b;
    struct TreeNode {
        TreeNode* children[26] = {};
        string w = "";
    };

    TreeNode* root = nullptr;

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    void fill(const vector<string>& wl) {

        for (const string& w : wl) {
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

    void dfs(TreeNode* node, vector<string>& res, int y, int x) {
        if (!node) return;
        if (!node->w.empty()) {
            res.push_back(node->w);
            node->w = "";
        }
        char tmp = b[y][x];
        b[y][x] = '#';

        for (const auto& d : dir) {
            int dy = y + d[0], dx = x + d[1];
            if (dy >=0 && dx >= 0 && dy < b.size() && dx < b[0].size() && b[dy][dx] != '#') {
                dfs(node->children[b[dy][dx] - 'a'], res, dy, dx);
            }
        }

        b[y][x] = tmp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        vector<string> res;
        root = new TreeNode();
        b = board;

        fill(words);

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                dfs(root->children[b[y][x] - 'a'], res, y, x);
            }
        }

        return res;

    }
};
