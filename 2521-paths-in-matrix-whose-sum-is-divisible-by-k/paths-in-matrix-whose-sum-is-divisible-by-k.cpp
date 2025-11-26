class Solution {
public:
int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    
    // DP table: dp[i][j][r] = number of paths to (i,j) with sum % k = r
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
    
    // Initialize starting point
    dp[0][0][grid[0][0] % k] = 1;
    
    // Fill the DP table
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int r = 0; r < k; r++) {
                if (dp[i][j][r] > 0) {
                    // Move right
                    if (j + 1 < n) {
                        int newRem = (r + grid[i][j + 1]) % k;
                        dp[i][j + 1][newRem] = (dp[i][j + 1][newRem] + dp[i][j][r]) % 1000000007;
                    }
                    // Move down
                    if (i + 1 < m) {
                        int newRem = (r + grid[i + 1][j]) % k;
                        dp[i + 1][j][newRem] = (dp[i + 1][j][newRem] + dp[i][j][r]) % 1000000007;
                    }
                }
            }
        }
    }
    
    return dp[m - 1][n - 1][0];
}
    
};