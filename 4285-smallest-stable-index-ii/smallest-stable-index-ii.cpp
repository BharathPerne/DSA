class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minFromRight(n);        
        minFromRight[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            minFromRight[i] = min(nums[i], minFromRight[i + 1]);
        }

        int max_ele = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_ele = max(max_ele, nums[i]);
            int min_ele = minFromRight[i];
            if (max_ele - min_ele <= k) {
                return i;
            }
        }
        return -1;
    }
};