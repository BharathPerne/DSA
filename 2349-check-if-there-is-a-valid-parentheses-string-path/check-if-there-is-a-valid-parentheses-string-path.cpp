class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Out of bounds
        if (i >= m || j >= n) {
            return false;
        }

        // Update balance
        if (grid[i][j] == '(') {
            balance++;
        } else {
            balance--;
        }

        // Invalid: more ')' than '('
        if (balance < 0) {
            return false;
        }

        // Too many opening brackets
        if (balance > m + n) {
            return false;
        }

        // Destination
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Already calculated
        if (dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }

        // Move down OR right
        return dp[i][j][balance] =
            solve(grid, i + 1, j, balance) ||
            solve(grid, i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Maximum possible balance is m+n
        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        return solve(grid, 0, 0, 0);
    }
};