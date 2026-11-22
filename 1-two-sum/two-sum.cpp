class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int tg = target - nums[i];
            auto it1 = find(nums.begin(), nums.begin() + i,tg);
            auto it2 = find(nums.begin() + i + 1, nums.end(), tg);
            if(it1!=nums.begin() + i){
                return {i,static_cast<int>(it1-nums.begin())};
            }else if(it2!=nums.end()){
                return {i,static_cast<int>(it2-nums.begin())};
            }            
        }
        return {-1,-1};
    }
};