class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Calculate total sum
        long long totalSum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                totalSum += grid[i][j];
            }
        }
        
        // If total sum is odd, cannot partition into two equal halves
        if (totalSum % 2 != 0) return false;
        
        long long targetSum = totalSum / 2;
        
        // Check horizontal partitions (cut between rows)
        long long runningSum = 0;
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                runningSum += grid[i][j];
            }
            if (runningSum == targetSum) {
                return true;
            }
        }
        
        // Check vertical partitions (cut between columns)
        runningSum = 0;
        for (int j = 0; j < cols - 1; j++) {
            for (int i = 0; i < rows; i++) {
                runningSum += grid[i][j];
            }
            if (runningSum == targetSum) {
                return true;
            }
        }
        
        return false;
    }
};