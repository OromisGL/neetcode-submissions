class Solution {
public:

    bool search(vector<int>& mx, int target) {
        int left = 0; 
        int right = mx.size() - 1; 

        if (mx[left] == target || mx[right] == target) return true;

        while (left < right) {
            int mid = (left + right) / 2;

            if (mx[mid] < target) {
                left = mid + 1;
            } else if (mx[mid] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        if (n == 1 && m == 1) return matrix[0][0] == target;

        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] >= target) {
                return search(matrix[i], target);
            }
        }

        return false;
    }
};












