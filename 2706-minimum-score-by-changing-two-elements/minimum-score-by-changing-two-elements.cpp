class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int a = abs(nums[2] - nums[n - 1]);
        int b = abs(nums[n - 3] - nums[0]);
        int c = abs(nums[n - 2] - nums[1]);

        return min(a, min(b, c));
    }
};