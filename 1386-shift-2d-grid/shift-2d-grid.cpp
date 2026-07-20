class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int total = row * col;
        k %= total;
        vector<vector<int>> result(row,vector<int> (col,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int idx = i * col + j;         
                int newIdx = (idx + k) % total; 

                int newRow = newIdx / col;
                int newCol = newIdx % col;
                result[newRow][newCol] = grid[i][j];
            }
        }
        return result;
    }
};