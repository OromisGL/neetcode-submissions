class Solution {
public:

    int dfs(int y, int x, vector<vector<int>>& grid) {
        if (y < 0 || x < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] == 0) return 0;

        grid[y][x] = 0;

        int found = dfs(y, x + 1, grid) + dfs(y,x - 1, grid) + dfs(y + 1, x, grid) + dfs(y - 1, x, grid) + 1;

        return found; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x]) {
                    count = max(count, dfs(y,x,grid));
                }
            }
        }

        return count;
    }
};
