// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int solve(vector<int>& nums, int index, int sum) {
//         if (index == nums.size()) {
//             return (sum % 3 == 0) ? sum : 0;
//         }
        
//         int include = solve(nums, index + 1, sum + nums[index]);
//         int exclude = solve(nums, index + 1, sum);
        
//         if (include % 3 == 0 && exclude % 3 == 0) {
//             return max(include, exclude);
//         } else if (include % 3 == 0) {
//             return include;
//         } else if (exclude % 3 == 0) {
//             return exclude;
//         } else {
//             return 0;
//         }
//     }
    
//     int maxSumDivThree(vector<int>& nums) {
//         return solve(nums, 0, 0);
//     }
// };

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        
        dp[0][0] = 0;
        dp[0][1] = -1;  // Not achievable
        dp[0][2] = -1;  // Not achievable
        
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            int rem = num % 3;
            
            for (int j = 0; j < 3; j++) {
                dp[i][j] = dp[i - 1][j];
                
                int prevRem = (j - rem + 3) % 3;
                if (dp[i - 1][prevRem] != -1) {
                    int newSum = dp[i - 1][prevRem] + num;
                    if (dp[i][j] == -1 || newSum > dp[i][j]) {
                        dp[i][j] = newSum;
                    }
                }
            }
        }
        
        return dp[n][0] != -1 ? dp[n][0] : 0;
    }
};