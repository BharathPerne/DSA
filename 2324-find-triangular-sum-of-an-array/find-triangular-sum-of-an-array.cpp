class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp(nums.size());
        int count=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            int index=0;
            for(int j=0;j<count;j++)
            {
            int val=nums[j]+nums[j+1];
            nums[index]=val%10;
            index++;
            }
            count--;
        }
        return nums[0];
    }
};