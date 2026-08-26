class Solution {
public:

    vector<pair<int,int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};

    void bfs(vector<vector<int>>& h, queue<pair<int,int>>& q, vector<vector<bool>>& reach) {

        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            for (const auto& d : dir) {
                int dy = cy + d.first;
                int dx = cx + d.second;

                if (dy >= 0 && dx >= 0 && dy < h.size() && dx < h[0].size() && h[dy][dx] >= h[cy][cx] && !reach[dy][dx]) {
                    q.push({dy,dx});
                    reach[dy][dx] = true;
                }
            }

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size(); 
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<bool>> pac(m, vector<bool>(n, false));

        queue<pair<int,int>> q1;

        for (int x = 0; x < n; x++) {
            q1.push({0,x});
            pac[0][x] = true;
        }
        for (int y = 0; y < m; y++) {
            q1.push({y,0});
            pac[y][0] = true;
        }

        bfs(h, q1, pac);

        queue<pair<int,int>> q2;

        for (int x = 0; x < n; x++) {
            q2.push({m - 1, x});
            atl[m - 1][x] = true;
        }
        for (int y = 0; y < m; y++) {
            q2.push({y, n - 1});
            atl[y][n - 1] = true;
        }

        bfs(h, q2, atl);

        vector<vector<int>> res;
       
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (pac[y][x] && atl[y][x]) res.push_back({y,x});
            }
        }

        return res;
    }
};
