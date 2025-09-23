class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0,j=2;
        int count=0;
        while(j<nums.size())
        {
            if((2*(nums[i]+nums[j]))==nums[j-1])
            {
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};