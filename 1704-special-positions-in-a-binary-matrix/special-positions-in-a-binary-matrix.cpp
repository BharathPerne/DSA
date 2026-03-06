// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int is_special=true;
//         int count=0;
//         for(int row=0;row<mat.size();row++)
//         {
//             for(int col=0;col<mat[row].size();col++)
//             {
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
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    bool isSpecial = true;
                    
                    // Check row i (all other columns)
                    for (int col = 0; col < n; col++) {
                        if (col != j && mat[i][col] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    
                    // Check column j (all other rows)
                    for (int row = 0; row < m; row++) {
                        if (row != i && mat[row][j] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    
                    if (isSpecial) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};