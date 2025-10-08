class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int m = potions.size();
        
        for(int spell : spells) {
            int left = 0, right = m - 1;
            int idx = m;
            
            while(left <= right) {
                int mid = left + (right - left) / 2;
                long long product = (long long)spell * potions[mid];
                
                if(product >= success) {
                    idx = mid;
                    right = mid - 1; 
                } else {
                    left = mid + 1; 
                }
            }
            
            ans.push_back(m - idx);
        }
        return ans;
    }
};