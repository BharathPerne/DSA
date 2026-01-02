class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> nums_occurence;
        for(int i=0;i<nums.size();i++)
        {
            auto it=find(nums_occurence.begin(),nums_occurence.end(),nums[i]);
            if(it!=nums_occurence.end())
            {
                return *it;
            }
            nums_occurence.push_back(nums[i]);
        }
        return 1;
    }
};