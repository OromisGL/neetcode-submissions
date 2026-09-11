class Solution {
public:

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 && n == 0) return 1;

        vector<vector<int>> deg(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (const auto& d : dir) {
                    int dy = i + d[0], dx = j + d[1];
                    if (dy >= 0 && dx >= 0 && dy < m && dx < n && matrix[dy][dx] > matrix[i][j]) deg[i][j]++;
                }
                if (deg[i][j] == 0) q.push({i,j});
            }
        }

        int len = 0;
        while (!q.empty()) {
            int sz = q.size();
            len++;
            while (sz--) {
                auto [y,x] = q.front();
                q.pop();

                for (const auto& d : dir) {
                    int dy = y + d[0], dx = x + d[1];
                    if (dy < 0 || dx < 0 || dy >= m || dx >= n || matrix[dy][dx] >= matrix[y][x]) continue;
                    if (--deg[dy][dx] == 0) {
                        q.push({dy,dx});
                    }
                }
            }
        }
        return len;
    }
};
