class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size()) {
            return 0;
        }

        if (j >= grid[0].size()) {
            return solve(grid, i + 1, 0);
        }

        int ans = 0;

        if (grid[i][j] == 1) {
            int row = 0, col = 0;

            for (int k = 0; k < grid[0].size(); k++) {
                if (grid[i][k] == 1)
                    row++;
            }

            for (int k = 0; k < grid.size(); k++) {
                if (grid[k][j] == 1)
                    col++;
            }

            if (row > 1 || col > 1) {
                ans = 1;
            }
        }

        return ans + solve(grid, i, j + 1);
    }

    int countServers(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }
};