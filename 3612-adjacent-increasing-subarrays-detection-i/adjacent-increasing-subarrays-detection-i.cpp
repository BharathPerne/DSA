class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i <= n - 2 * k; i++) {
            bool firstValid = true;
            bool secondValid = true;
            
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    firstValid = false;
                    break;
                }
            }
            
            for (int j = i + k + 1; j < i + 2 * k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    secondValid = false;
                    break;
                }
            }
            
            if (firstValid && secondValid) {
                return true;
            }
        }
        
        return false;
    }
};