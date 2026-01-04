class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            int sum=0;  
            for(int j=2;j<=nums[i]/2;j++)
            {
                if(count>5)
                {
                    break;
                }
                if(nums[i]%j==0)
                {
                    count++;
                    sum+=j;
                }
            }
            if(count==2)
            {
                result+=sum+1+nums[i];
            }
        }
        return result;
    }
};