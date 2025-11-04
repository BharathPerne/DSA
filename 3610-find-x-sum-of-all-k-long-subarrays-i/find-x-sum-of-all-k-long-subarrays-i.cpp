class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            
            vector<pair<int, int>> elements;
            for (auto& [val, count] : freq) {
                elements.push_back({count, val});
            }
            
            sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            
            vector<int> topValues;
            for (int idx = 0; idx < x && idx < elements.size(); idx++) {
                topValues.push_back(elements[idx].second);
            }
            
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                if (find(topValues.begin(), topValues.end(), nums[j]) != topValues.end()) {
                    sum += nums[j];
                }
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};