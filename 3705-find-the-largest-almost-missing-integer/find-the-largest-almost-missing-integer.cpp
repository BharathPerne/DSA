class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            unordered_map<int, int> freq;
            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;
            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }
            return ans;
        }else if(k==n){
            int max_ele=INT_MIN;
            for(int i=0;i<n;i++){
                max_ele=max(max_ele,nums[i]);
            }
            return max_ele;
        }else{
            int count_0=0,count_n=0;
            for(int i=0;i<n;i++){
                if(nums[0]==nums[i]){
                    count_0++;
                }else if(nums[n-1]==nums[i]){
                    count_n++;
                }
            }
            if (count_0 == 1 && count_n == 1) {
            return max(nums[0], nums[n - 1]);
        }

        if (count_0 == 1) {
            return nums[0];
        }

        if (count_n == 1) {
            return nums[n - 1];
        }

        return -1;
        }
        return -1;
    }
};