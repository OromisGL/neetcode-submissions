class Solution {
public:
    // left = 

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& seen) {
        if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() || seen[y][x] || grid[y][x] == '0') return;
        
        seen[y][x] = true;
        dfs(x + 1, y, grid, seen); 
        dfs(x - 1, y, grid, seen);
        dfs(x, y + 1, grid, seen);
        dfs(x, y - 1, grid, seen);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int count = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == '1' && !seen[y][x]) {
                    dfs(x,y,grid,seen);
                    count++;
                }
            }
        }
        return count;
    }
};
