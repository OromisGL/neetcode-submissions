class Solution {
public:

    vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

    void bfs(int y, int x, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({y,x});

        while (!q.empty()) {
            pair<int,int> pos = q.front();
            q.pop();

            int cx = pos.second;
            int cy = pos.first; 
            
            for (const auto& d : dir) {
                int dy = cy + d.first;
                int dx = cx + d.second;
                if(dx < 0 || dy < 0 || dx >= grid[0].size() || dy >= grid.size()) continue;
                if (grid[dy][dx] == '1'){
                    grid[dy][dx] = '0';
                    q.push({dy,dx});
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

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
