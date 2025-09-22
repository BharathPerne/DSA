class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> map;
        int max=1;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(nums[i])!=map.end())
            {
                map[nums[i]]++;
                if(max<map[nums[i]])
                {
                    max=map[nums[i]];
                }
            }
            else
            {
                map[nums[i]]=1;
            }
        }
        int ans=0;
        for(auto [key,val]:map)
        {
            if(val==max)
            {
                ans+=max;
            }
        }
        return ans;
    }
};