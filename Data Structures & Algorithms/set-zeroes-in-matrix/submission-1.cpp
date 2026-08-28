class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size(); 
        queue<pair<int,int>> q;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (!mat[y][x]) q.push({y,x});
            }
        }

        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < m; i++) {
                mat[i][x] = 0;
            }
            for (int i = 0; i < n; i++) {
                mat[y][i] = 0;
            }
        }
    }
};
