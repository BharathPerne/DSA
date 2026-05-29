class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int min=0;
            while(num){
                min+=num%10;
                num=num/10;
            }
            ans=ans>min ? min : ans;
        }
        return ans;
    }
};