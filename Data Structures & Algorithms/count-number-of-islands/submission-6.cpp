class Solution {
public:
    vector<pair<int,int>> dir {{0,1},{-1,0},{0,-1},{1,0}};

    void bfs(int y, int x, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({y,x});

        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for (const auto& d : dir) {
                int dy = cy + d.first;
                int dx = cx + d.second;

                if (dy < 0 || dx < 0 || dy >= grid.size() || dx >= grid[0].size() || grid[dy][dx] == '0') continue;
                q.push({dy,dx});
                grid[dy][dx] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == '1') {
                    bfs(y,x,grid);
                    count++;
                }
            }
        }

        return count;

    }
};
