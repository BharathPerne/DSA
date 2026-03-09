class Solution {
private:
    const int MOD = 1000000007;
    
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // dp0[i][j]: number of stable arrays with i zeros and j ones ending with 0
        // dp1[i][j]: number of stable arrays with i zeros and j ones ending with 1
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));
        
        // Initialize base cases
        // Arrays with only zeros (j = 0)
        for (int i = 1; i <= min(zero, limit); i++) {
            dp0[i][0] = 1;
        }
        
        // Arrays with only ones (i = 0)
        for (int j = 1; j <= min(one, limit); j++) {
            dp1[0][j] = 1;
        }
        
        // Fill DP tables
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) continue;
                
                // Calculate dp0[i][j] - ending with 0
                if (i > 0) {
                    for (int t = 1; t <= min(limit, i); t++) {
                        // Add sequences ending with 1, then t zeros
                        dp0[i][j] = (dp0[i][j] + dp1[i - t][j]) % MOD;
                    }
                }
                
                // Calculate dp1[i][j] - ending with 1
                if (j > 0) {
                    for (int t = 1; t <= min(limit, j); t++) {
                        // Add sequences ending with 0, then t ones
                        dp1[i][j] = (dp1[i][j] + dp0[i][j - t]) % MOD;
                    }
                }
            }
        }
        
        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};