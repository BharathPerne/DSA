class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int tg = target - nums[i];

            if (mp.find(tg) != mp.end()) {
                return {mp[tg], i};
            }

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};