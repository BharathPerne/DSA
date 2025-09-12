#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        return helper(nums, k, 0, 1);
    }

private:
    int helper(vector<int>& nums, int k, int i, int j) {
        if (i >= nums.size() - 1) {
            return 0;
        }
        if (j >= nums.size()) {
            return helper(nums, k, i + 1, i + 2);
        }
        int count = 0;
        if (nums[i] == nums[j] && (i * j) % k == 0) {
            count = 1;
        }
        return count + helper(nums, k, i, j + 1);
    }
};