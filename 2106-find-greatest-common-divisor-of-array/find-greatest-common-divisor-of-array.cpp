class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_num=INT_MIN;
        int min_num=INT_MAX;
        for(int i=0;i<nums.size();i++){
            max_num=max(max_num,nums[i]);
            min_num=min(min_num,nums[i]);
        }
        return gcd(max_num,min_num);
    }
};