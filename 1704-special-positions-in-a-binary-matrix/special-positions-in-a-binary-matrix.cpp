// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int is_special=true;
//         int count=0;
//         for(int row=0;row<mat.size();row++)
//         {
//             for(int col=0;col<mat[row].size();col++)
//             {
//                 if (mat[row][col] == 1) {                      
//                 is_special=true;
//                 for(int i=0;i<mat[row].size();i++)
//                 {
//                     if(i!=col&&mat[row][i]==1)
//                     {
//                         is_special=false;
//                         break;
//                     }
//                 }
//                 for (int j = 0; j < mat.size(); j++) {
//                         if (j != row && mat[j][col] == 1) {
//                             is_special = false;
//                             break;
//                         }
//                     }
                    
//                     if (is_special) {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        int count = 0;
        
        // Calculate row and column sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }
        
        // Check for special positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};