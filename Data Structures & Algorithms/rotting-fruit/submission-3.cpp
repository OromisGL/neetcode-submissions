class Solution {
public:

    vector<pair<int,int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& min, int& fresh) {

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();

                for (const auto& d : dir) {
                    int dy = cy + d.first;
                    int dx = cx + d.second;
                    if (dy < 0 || dx < 0 || dy >= grid.size() || dx >= grid[0].size() || grid[dy][dx] == 2 || !grid[dy][dx]) continue;

                    grid[dy][dx] = 2;
                    q.push({dy,dx});
                    fresh--;
                }
            }

            if (!q.empty()) min++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int min = 0;
        int fresh = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == 2) {
                    q.push({y,x});
                }
                if (grid[y][x] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        bfs(grid, q, min, fresh);

        return fresh != 0 ? -1 : min;
    }
};
