class Solution {
public:
    int countPartitions(vector<int>& nums) {
        //In this one two approach are there one is we can take the int and do the operation and also we can take the bool data type for the memory optimization in this to find out the odd numbers we are fliping the variable then we are checking the odd or even.
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