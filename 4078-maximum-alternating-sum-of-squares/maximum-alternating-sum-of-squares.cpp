class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
    return abs(a) > abs(b);
});
        int i=0,j=nums.size()-1;
        long long result=0;
        int flag=true;
        while(i<=j){
            if(flag){
                result+=(nums[i]*nums[i]);
                i++;
                flag=false;
            }else{
                result-=(nums[j]*nums[j]);
                j--;
                flag=true;
            }
        }        
        return result;
    }
};