// class Solution {
// public:
// long long max(long long num1,long long num2)
// {
//     if(num1>=num2)
//     {
//         return num1;
//     }
//     else
//     {
//         return num2;
//     }
// }
//     long long maxSubarraySum(vector<int>& nums, int k) {
//         // int remain=nums.size()%k;
//         // sort(nums.begin(),nums.end());
//         long long result=0;
//         vector<long long> sum;
//         for(int i=0;i<nums.size();i++)
//         {
//             result+=nums[i];
//             if(i+1>=k)
//             {
//                 sum.push_back(result);
//                 result-=nums[i-k+1];
//             }
//         }
//         int max_ele=INT_MIN;
//         long long output=0;
//         for(int i=0;i<sum.size();i++)
//         {
            
//             if(sum[i]>0)
//             {
//                 output+=sum[i];
//             }
//             else if(!output)
//             {
//                 max_ele=max(max_ele,sum[i]);
//             }
//         }
//         return output==0 ? max_ele :output;
//     }
// };


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long result = LLONG_MIN;
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int remainder = i % k;
            
            if (minPrefix[remainder] != LLONG_MAX) {
                result = max(result, prefix[i] - minPrefix[remainder]);
            }
            
            minPrefix[remainder] = min(minPrefix[remainder], prefix[i]);
        }
        
        return result;
    }
};