class Solution {
public:
int solve(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return solve(num2, num1 % num2);
}
    int minOperations(vector<int>& nums) {
        int one_count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                one_count++;
            }
        }
        if(one_count)
        {
            return nums.size()-one_count;
        }
        int operation=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int gcd=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                gcd=solve(gcd,nums[j]);
                if(gcd==1)
                {
                    operation=min(operation,j-i);
                }
            }
        }
        if(operation==INT_MAX)
        {
            return -1;
        }
        return operation+nums.size()-1;
    }
};