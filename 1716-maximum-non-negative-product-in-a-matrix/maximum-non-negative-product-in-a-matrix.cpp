class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        // DP tables to store max and min products at each cell
        vector<vector<long long>> maxProd(m, vector<long long>(n));
        vector<vector<long long>> minProd(m, vector<long long>(n));
        
        // Initialize starting cell
        maxProd[0][0] = minProd[0][0] = grid[0][0];
        
        // Initialize first column
        for (int i = 1; i < m; i++) {
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0] * grid[i][0];
        }
        
        // Initialize first row
        for (int j = 1; j < n; j++) {
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1] * grid[0][j];
        }
        
        // Fill DP tables
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long fromTopMax = maxProd[i-1][j];
                long long fromTopMin = minProd[i-1][j];
                long long fromLeftMax = maxProd[i][j-1];
                long long fromLeftMin = minProd[i][j-1];
                
                if (grid[i][j] > 0) {
                    maxProd[i][j] = max(fromTopMax, fromLeftMax) * grid[i][j];
                    minProd[i][j] = min(fromTopMin, fromLeftMin) * grid[i][j];
                } 
                else if (grid[i][j] < 0) {
                    maxProd[i][j] = min(fromTopMin, fromLeftMin) * grid[i][j];
                    minProd[i][j] = max(fromTopMax, fromLeftMax) * grid[i][j];
                } 
                else {
                    // If grid[i][j] == 0, both max and min become 0
                    maxProd[i][j] = minProd[i][j] = 0;
                }
            }
        }
        
        long long result = maxProd[m-1][n-1];
        
        // If result is negative, return -1
        if (result < 0) {
            return -1;
        }
        
        return result % MOD;
    }
};