class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9,false));
        vector<vector<bool>> cols(9, vector<bool>(9,false));
        vector<vector<bool>> boxes(9, vector<bool>(9,false));

        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                if (board[r][c] == '.') continue;
                
                int d = board[r][c] - '1';
                int b = (r / 3) * 3 + (c / 3);

                if (rows[r][d] || cols[c][d] || boxes[b][d]) return false;
                rows[r][d] = true;
                cols[c][d] = true;
                boxes[b][d] = true;
            }
        }
        return true;
    }
};
