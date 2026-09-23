class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int val = sum - x;
        int max_ele = -1;
        int left = 0;
        int sum_a = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_a += nums[i];

            while (left < nums.size() && sum_a > val) {
                sum_a -= nums[left];
                left++;
            }
            if (val == sum_a) {
                max_ele = max(max_ele, i - left + 1);
            }
        }
        return max_ele == -1 ? -1 : nums.size() - max_ele;
    }
};