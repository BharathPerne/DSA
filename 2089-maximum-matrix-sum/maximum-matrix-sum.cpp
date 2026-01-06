#include <vector>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int minAbs = INT_MAX;  
        int totalNegCount = 0; 
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] < 0) {
                    totalNegCount++;
                }
                
                int absVal = abs(matrix[i][j]);
                if(minAbs > absVal) {
                    minAbs = absVal;
                }
                
                result += absVal;
            }
        }
        if(totalNegCount % 2 != 0) {
            result -= minAbs * 2;
        }
        
        return result;
    }
};