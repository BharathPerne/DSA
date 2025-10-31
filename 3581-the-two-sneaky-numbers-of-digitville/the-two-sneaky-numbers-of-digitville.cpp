class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto ch:mp)
        {
            if(ch.second==2)
            {
                ans.push_back(ch.first);
            }
        }
        return ans;
    }
};