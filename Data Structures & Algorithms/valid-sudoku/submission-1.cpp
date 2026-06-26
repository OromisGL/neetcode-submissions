class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '1';
                int idx = (i / 3) * 3 + (j / 3);

                if (box[idx][digit] || col[j][digit] || row[i][digit]) return false;
                box[idx][digit] = true;
                col[j][digit] = true;
                row[i][digit] = true;
            }
        }
        return true;
    }
};
