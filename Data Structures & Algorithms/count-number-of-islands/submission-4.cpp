class Solution {
public:

    void dfs(int y, int x, vector<vector<char>>& grid) {
        if (y < 0 || x < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] == '0') return;
        grid[y][x] = '0';
        dfs(y, x + 1, grid);
        dfs(y, x - 1, grid);
        dfs(y + 1, x, grid);
        dfs(y - 1, x, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == '1'){
                    dfs(y,x,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
