// class Solution {
// public:
//     int maxIncreasingSubarrays(vector<int>& nums) {
//         int ans;
//         for(int k=1;k<nums.size()/2;k++)
//         {
//         for(int i=0;i<nums.size();i++)
//         {
//             bool firstvalue=false;
//             bool secondvalue=false;
//             for (int j = i + 1; j < i + k&&j<nums.size(); j++) {
//                 firstvalue=true;
//                 if (nums[j] <= nums[j - 1]) {
//                     firstvalue = false;
//                     break;
//                 }
//             }
            
//             for (int j = i + k + 1;j < i + 2 * k&&j<nums.size(); j++) {
//                 secondvalue=true;
//                 if (nums[j] <= nums[j - 1]) {
//                     secondvalue = false;
//                     break;
//                 }
//             }
//             if(firstvalue&&secondvalue)
//             {
//                 ans=k;
//             }
//         }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        
        int maxK = 0;
        
        for (int i = 0; i < n; i++) {
            int len = dp[i];
            
            if (i + 1 < n && nums[i + 1] > nums[i]) {
                continue;
            }
            
            if (len >= 2) {
                int candidate1 = len / 2;
                if (candidate1 > maxK) {
                    maxK = candidate1;
                }
            }
            
            if (i - len >= 0) {
                int prevLen = dp[i - len];
                int candidate2 = min(len, prevLen);
                if (candidate2 > maxK) {
                    maxK = candidate2;
                }
            }
            
            if (i + 1 < n) {
                int nextLen = dp[i + 1];
                int candidate3 = min(len, nextLen);
                if (candidate3 > maxK) {
                    maxK = candidate3;
                }
            }
        }
        
        return maxK;
    }
};