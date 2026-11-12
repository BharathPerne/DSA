class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int result_inc = 1;
        int result_desc = 1;
        int ans = 0;
        for (int i = 1; i < nums.size();) {
            int result_inc = 1;
            int result_desc = 1;
            if(nums[i-1]==nums[i]){
                i++;
            }
            while (i < nums.size() && nums[i - 1] < nums[i]) {
                result_inc++;
                i++;
            }
            while (i < nums.size() && nums[i - 1] > nums[i]) {
                result_desc++;
                i++;
            }
            ans = max(ans, max(result_inc, result_desc));
        }
        return ans;
    }
};