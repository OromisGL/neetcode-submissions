class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size(); 
        int row0 = 0;
        int col0 = 0;

        for (int i = 0; i < m; i++) {
            if (!mat[i][0]) col0 = 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (!mat[0][i]) row0 = 1;
        }

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (!mat[y][x]) {
                    mat[y][0] = 0;
                    mat[0][x] = 0;
                }
            }
        }

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                if (!mat[y][0] || !mat[0][x]) {
                    mat[y][x] = 0;
                }
            }
        }

        if (row0) {
            for (int i = 0; i < n; i++) {
                if (mat[0][i] != 0) mat[0][i] = 0;
            }
        }
        if (col0) {
            for (int i = 0; i < m; i++) {
                if (mat[i][0] != 0) mat[i][0] = 0;
            }
        }

    }
};
