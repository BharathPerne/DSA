class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        for(int i=0;i<queries.size();i++)
        {
            // int row=queries[i][0];
            // for(int j=queries[i][0];j<=queries[i][3];j++)
            // {
            //     matrix[row][j]++;
            // }
            // int col=queries[i][1];
            // for(int k=queries[i][1];k<=queries[i][2];k++)
            // {
            //     matrix[k][col]++;
            // }
            int row=queries[i][0];
            for(int j=queries[i][0];j<=queries[i][2];j++)
            {
                for(int k=queries[i][1];k<=queries[i][3];k++)
                {
                    matrix[row][k]++;
                }
                row++;
                // int col=queries[i][1];
                // for(int k=queries[i][1];k<=queries[i][2];k++)
                // {
                //     matrix[k][col]++;
                // }
            }
        }
        return matrix;
    }
};