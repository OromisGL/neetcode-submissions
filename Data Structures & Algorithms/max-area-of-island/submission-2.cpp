class Solution {
public:

    vector<pair<int,int>> dir = {{0,0},{0,1},{-1,0},{0,-1},{1,0}};
    
    int bfs(int y, int x, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({y,x});
        int count = 0;

        while (!q.empty()) {
            pair<int,int> pos = q.front();
            q.pop();

            int cx = pos.second;
            int cy = pos.first;

            for (const auto& d : dir) {
                int dx = cx + d.second;
                int dy = cy + d.first;

                if (dy < 0 || dx < 0 || dy >= grid.size() || dx >= grid[0].size()) continue;

                if(grid[dy][dx] == 1) {
                    grid[dy][dx] = 0;
                    q.push({dy,dx});
                    count++;
                }
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return grid[0][0];
        int maxcount = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == 1) {
                    maxcount = max(maxcount, bfs(y,x,grid));
                }
            }
        }
        return maxcount;
    }
};
