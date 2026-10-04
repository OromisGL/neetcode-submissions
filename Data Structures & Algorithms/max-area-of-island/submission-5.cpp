class Solution {
public:

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    void bfs(int y, int x, vector<vector<int>>& grid, int& count){
        queue<pair<int,int>> q;
        q.push({y,x});
        grid[y][x] = '#';

        while (!q.empty()) {
            int cx = q.front().second, cy = q.front().first;
            q.pop();
            for (auto& d : dir) {
                int dy = cy + d[0], dx = cx + d[1];
                if (dy >= 0 && dx >= 0 && dy < grid.size() && dx < grid[0].size() && grid[dy][dx] == 1) {
                    q.push({dy,dx});
                    grid[dy][dx] = 0;
                    count++;
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxA = 0;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == 1) {
                    int count = 1;
                    bfs(y,x,grid,count);
                    maxA = max(maxA, count);
                }
            }
        }
        return maxA;
    }
};
