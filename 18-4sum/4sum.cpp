
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<vector<int>> res;

        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {

                        long long sum = 0;
                        sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            ans.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                        if (nums[i] == nums[j] && nums[j] == nums[k] &&
                            nums[k] == nums[l]) {
                            break;
                        }
                    }
                   if (nums[i] == nums[j] && nums[j] == nums[k]){
                        break;
                    }
                }
                 if (nums[i] == nums[j]){
                    break;
                }
            }
        }

        vector<vector<int>> result(ans.begin(), ans.end());

        return result;
    }
};
