class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // int ans=0;
        // int left=0,right=0;
        // int result=0;
        // for(int i=0;i<nums.size();i++){
        //     if((i-left+1)>r||(((i-left+1)>l&&nums[i]>0&&result>nums[i]))){
        //         result-=nums[left];
        //        // ans=-nums[left];
        //         left++;
        //     }
        //      result+=nums[i];
        //     if((i-left+1)>=l&&(i-left+1)<=r&&result>0){
        //       ans=min(ans,result);
        //        //ans=ans+result;
        //     }
        // }
        // return ans!=INT_MAX ? ans :-1;
        int ans = INT_MAX;
        for (int i = l; i <= r; i++) {
            int left = 0;
            int result = 0;
            for (int j = 0; j < nums.size(); j++) {
               result += nums[j];

                if ((j - left + 1) > i) {
                    result -= nums[left];
                    left++;
                }

                if ((j - left + 1) == i && result > 0) {
                    ans = min(ans, result);
                }
            }
        }
        return ans==INT_MAX ? -1 :ans;
    }
};