class Solution {
public:
bool find(vector<int> &nums,int original)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==original)
        {
            return true;
        }
    }
    return false;
}
    int findFinalValue(vector<int>& nums, int original) {
        while(true)
        {
            if(find(nums,original))
            {
                original=original*2;
            }
            else
            {
                return original;
            }
        }
    }
};