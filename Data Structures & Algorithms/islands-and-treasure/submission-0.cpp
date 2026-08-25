class Solution {
public:

    vector<pair<int,int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};


    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        while (!q.empty()) {
            pair<int,int> pos = q.front();
            q.pop();

            int cy = pos.first;
            int cx = pos.second;

            for (const auto& d : dir) {
                int dy = cy + d.first;
                int dx = cx + d.second;

                if (dy < 0 || dx < 0 || dy >= grid.size() || dx >= grid[0].size() || grid[dy][dx] == -1 || grid[dy][dx] == 0) continue;
                if (grid[dy][dx] == INT_MAX) { 
                    q.push({dy,dx});
                    grid[dy][dx] = grid[cy][cx] + 1;
                }
            }
        }

    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == 0) {
                    q.push({y,x});
                }
            }
        }

        bfs(grid, q);
    }
};
