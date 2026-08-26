class Solution {
public:
    int m = 0; 
    int n = 0;
    vector<pair<int,int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
    void bfs(int y, int x, vector<vector<char>>& b) {
        queue<pair<int,int>> q;
        q.push({y,x});

        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            b[cy][cx] = '#';

            for (const auto& d : dir) {
                int dy = cy + d.first;
                int dx = cx + d.second;

                if (dy < 0 || dx < 0 || dy >= m || dx >= n || b[dy][dx] == 'X' || b[dy][dx] == '#') continue;
                b[dy][dx] = '#';
                q.push({dy,dx});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(); 
        n = board[0].size();

        for (int y = 0; y < m; y++) {
            if (board[y][0] == 'O') {
                bfs(y,0,board);
            } 
            if (board[y][n - 1] == 'O') {
                bfs(y,n - 1,board);
            }
        }
        for (int x = 0; x < n; x++) {
            if (board[0][x] == 'O') {
                bfs(0,x,board);
            } 
            if (board[m - 1][x] == 'O') {
                bfs(m - 1,x,board);
            }
        }

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (board[y][x] == 'O') {
                    board[y][x] = 'X';
                } else if (board[y][x] == '#'){
                    board[y][x] = 'O';
                }
            }
        }
    }
};
