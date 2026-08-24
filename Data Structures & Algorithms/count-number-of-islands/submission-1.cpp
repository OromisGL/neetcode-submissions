class Solution {
public:

    vector<pair<int, int>> dir = {{0,-1},{0,1},{-1,0},{1,0},};

    void bfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({y,x});

        while (!q.empty()) {
            pair<int,int> cell = q.front();
            q.pop();

            int x = cell.second;
            int y = cell.first;

            if (grid[y][x] == '1' && !vis[y][x]) {
                vis[y][x] = true;
                for (const auto& d : dir) {
                    int dy = y + d.first;
                    int dx = x + d.second;
                    if (y < 0 || x < 0 || dy >= grid.size() || dx >= grid[0].size()) continue;
                    if (grid[dy][dx] == '1' && !vis[dy][dx]) {
                        q.push({dy,dx});
                        vis[y][x] = true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int count = 0;

        for(int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if(grid[y][x] == '1' && !vis[y][x]) {
                    bfs(x,y,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
