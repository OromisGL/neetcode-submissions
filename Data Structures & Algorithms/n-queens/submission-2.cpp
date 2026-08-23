class Solution {
public:
    // cols |= cols & (1 << col)
    // diag1 |= (1 << (row - col + n))
    // diag2 |= (1 << (row + col))

    vector<string> board;
    vector<vector<string>> result;

    void backtrack(int row, int cols, int diag1, int diag2, int n) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int bit = (1 << col);
            int diag1bit = (1 << (row - col + n));
            int diag2bit = (1 << (row + col));

            if (!(cols & bit) 
                && !(diag1 & diag1bit)
                && !(diag2 & diag2bit)
                ) {
                    board[row][col] = 'Q';

                    backtrack(row + 1, cols | bit, diag1 | diag1bit, diag2 | diag2bit, n);
                    board[row][col] = '.';
                }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n,'.'));
        backtrack(0, 0, 0, 0, n);
        return result;
    }
};
