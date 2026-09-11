class Solution {
public:

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        if (m == 0 && n == 0) return 1;

        queue<pair<int,int>> q;
        vector<vector<int>> deg(m, vector<int>(n, 0));

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                for (const auto& d : dir ) {
                    int dy = y + d[0], dx = x + d[1];
                    if (dy >= 0 && dx >= 0 && dy < m && dx < n && mat[dy][dx] > mat[y][x]) deg[y][x]++;
                }
                if (deg[y][x] == 0) q.push({y,x});
            }
        }

        int len = 0;
        while (!q.empty()) {
            int sz = q.size();
            len++;
            while (sz--) {
                auto [y,x] = q.front();
                q.pop();
                for (const auto& d : dir ) {
                    int dy = y + d[0], dx = x + d[1];
                    if (dy < 0 || dx < 0 || dy >= m || dx >= n || mat[dy][dx] >= mat[y][x]) continue;
                    if (--deg[dy][dx] == 0) q.push({dy,dx});
                } 
            }
        }

        return len;

    }
};
