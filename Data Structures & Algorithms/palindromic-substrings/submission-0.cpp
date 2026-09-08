class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        if (n == 1) return n;

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        int count = n;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) count++;
            }
        }
        return count;
    }
};
