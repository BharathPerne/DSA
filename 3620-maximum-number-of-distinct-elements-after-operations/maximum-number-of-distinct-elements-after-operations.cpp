// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {
//         map<int,int> arr;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++)
//         {
//             int val=nums[i];
//             for(int j=-k;j<=k;j++)
//             {
//                 int ans=val+j;
//                 if((arr.find(ans)!=arr.end()))
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     arr[ans]=1;
//                     break;
//                 }
//             }
//         }
//         return arr.size();
//     }
// };
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int count = 0;

        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if(prev < minVal) {
                //nums[i] = nums[i]-k;
                prev = minVal;
                count++;
            } else if(prev < nums[i] + k) {
                //nums[i] = prev+1;
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};

