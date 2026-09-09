class Solution {
public:
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    using Cell = tuple<int,int,int>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 1) return grid[0][0];

        priority_queue<Cell, vector<Cell>, greater<Cell>> q;

        q.emplace(grid[0][0],0,0);
        grid[0][0] = -1;

        while (!q.empty()) {
            auto [time, y, x] = q.top();
            q.pop();

            if (y == n - 1 && x == n - 1) return time;

            for (const auto& d : dir) {
                int dy = y + d[0], dx = x + d[1];

                if (dy < 0 || dx < 0 || dy >= n || dx >= n || grid[dy][dx] == -1) continue;

                q.emplace(max(time, grid[dy][dx]), dy, dx);
                grid[dy][dx] = -1;
            }
        }

        return 0;
    }
};
