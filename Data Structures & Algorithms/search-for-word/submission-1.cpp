class Solution {
public:

    bool find(vector<vector<char>>& b, int x, int y, int i, string& w) {
        if (i == w.size()) {
            return true;
        }

        if (x < 0 || y < 0 || x >= b[0].size() || y >= b.size() || i >= w.size() || b[y][x] != w[i]) return false;

        char temp = b[y][x];
        b[y][x] = '#';

        bool found = find(b, x + 1, y, i + 1, w) || find(b, x - 1, y, i + 1, w) ||
                     find(b, x, y + 1, i + 1, w) || find(b, x, y - 1, i + 1, w);

        b[y][x] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        if (n == 1 && m == 1 && word.size() == 1) return board[0][0] == word[0];

        char start = word[0];

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (board[y][x] != start) continue;

                if (find(board, x, y, 0, word)) return true;
            }
        }

        return false;

    }
};
