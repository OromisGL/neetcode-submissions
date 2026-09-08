class Solution {
public:

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    using Cell = tuple<int,int,int>;

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<Cell, vector<Cell>, greater<Cell>> q;
        q.emplace(grid[0][0],0,0);
        grid[0][0] = -1;

        while (!q.empty()) {
            
            auto [time, cy, cx] = q.top();
            q.pop();
            if (cy == m - 1 && cx == n - 1) return time;

            for (const auto& d : dir) {
                int dy = cy + d[0];
                int dx = cx + d[1];

                if (dy < 0 || dx < 0 || dy >= n || dx >= m || grid[dy][dx] == -1) continue;

                q.emplace(max(time, grid[dy][dx]), dy,dx);
                grid[dy][dx] = -1;
            }
        }
        return 0;
    }
};
