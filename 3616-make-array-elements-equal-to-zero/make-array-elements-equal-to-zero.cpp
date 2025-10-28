class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int start = 0; start < n; start++) {
            if (nums[start] == 0) {
                // Try right direction
                if (simulate(nums, start, 1)) {
                    count++;
                }
                // Try left direction  
                if (simulate(nums, start, -1)) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    bool simulate(vector<int> nums, int start, int direction) {
        int n = nums.size();
        int curr = start;
        
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                // Move in current direction
                curr += direction;
            } else {
                // Decrement the value
                nums[curr]--;
                // Reverse direction
                direction = -direction;
                // Take a step in new direction
                curr += direction;
            }
        }
        
        // Check if all elements are zero
        for (int num : nums) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};