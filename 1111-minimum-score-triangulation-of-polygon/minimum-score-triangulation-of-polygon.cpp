class Solution {
public:
    vector<vector<int>> memo;
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(values, 0, n - 1);
    }
    
    int solve(vector<int>& values, int i, int j) {
        if (j - i < 2) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        int minScore = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int current = values[i] * values[k] * values[j];
            int left = solve(values, i, k);
            int right = solve(values, k, j);
            
            minScore = min(minScore, current + left + right);
        }
        
        return memo[i][j] = minScore;
    }
};