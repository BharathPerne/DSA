class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                count++;
            }
        }
        if(count%2==0)
        {
            return nums.size()-1;
        }
        else
        {
            return 0;
        }
    }
};