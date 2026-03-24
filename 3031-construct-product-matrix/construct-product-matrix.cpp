class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        int totalCells = n * m;
        
        vector<int> flat(totalCells);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flat[i * m + j] = grid[i][j] % MOD;
            }
        }
        
        vector<int> prefix(totalCells + 1, 1);
        for (int i = 0; i < totalCells; i++) {
            prefix[i + 1] = (prefix[i] * flat[i]) % MOD;
        }
        
        vector<int> suffix(totalCells + 1, 1);
        for (int i = totalCells - 1; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * flat[i]) % MOD;
        }
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                result[i][j] = (prefix[idx] * suffix[idx + 1]) % MOD;
            }
        }
        
        return result;
    }
};