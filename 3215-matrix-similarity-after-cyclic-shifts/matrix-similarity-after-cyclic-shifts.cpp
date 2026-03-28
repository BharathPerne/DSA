class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> original = mat;
        int m = mat.size();
        int n = mat[0].size();
        
        k = k % n;
        if (k == 0) return true;
        
        for (int i = 0; i < m; i++) {
            vector<int> newRow(n);
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    newRow[(j + k) % n] = mat[i][j];
                } else {
                    newRow[(j - k + n) % n] = mat[i][j];
                }
            }
            mat[i] = newRow;
        }
        
        return original == mat;
    }
};