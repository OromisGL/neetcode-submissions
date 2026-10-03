class Solution {
public:
    int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

    void bfs(int y, int x, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        grid[y][x] = '#';
        q.push({y,x});

        while (!q.empty()) {
            int cx = q.front().second, cy = q.front().first;
            q.pop();

            for (const auto& d : dir) {
                int dy = cy + d[0], dx = cx + d[1];
                if (dy >= 0 && dx >= 0 && dy < grid.size() && dx < grid[0].size() && grid[dy][dx] != '#' && grid[dy][dx] == '1') {
                    q.push({dy,dx});
                    grid[dy][dx] = '#';
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == '1') {
                    bfs(y,x,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
