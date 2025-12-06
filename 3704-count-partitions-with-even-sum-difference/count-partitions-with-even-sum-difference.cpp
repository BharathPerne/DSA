class Solution {
public:
    int countPartitions(vector<int>& nums) {
        bool flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                flag=!flag;
            }
        }
        if(!flag)
        {
            return nums.size()-1;
        }
        else
        {
            return 0;
        }
    }
};