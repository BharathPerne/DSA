class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int sum=nums[i]+nums[j];
                for(int k=j+1;k<nums.size();k++)
                {
                    if(sum>nums[k])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};