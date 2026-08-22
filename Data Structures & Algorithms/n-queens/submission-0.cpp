class Solution {
public:

    void backtrack(int row, int cols, int diag1, int diag2, int n, vector<vector<string>>& result, vector<string>& board) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int bit = (1 << col);   
            if (!(cols & bit) && !(diag1 & (1 << (row - col + n))) && !(diag2 & (1 << (row + col)))) {
                board[row][col] = 'Q';
                backtrack(row + 1, cols | bit, diag1 | (1 << (row - col + n)), diag2 | (1 << (row + col)), n, result, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n,'.'));

        backtrack(0, 0, 0, 0, n, result, board);

        return result;

    }
};
