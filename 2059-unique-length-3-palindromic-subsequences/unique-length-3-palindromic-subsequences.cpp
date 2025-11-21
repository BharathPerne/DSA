class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        
        vector<int> first(26, INT_MAX);
        vector<int> last(26, INT_MIN);
        
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = max(last[idx], i);
        }
        
        int result = 0;
        
        for (int i = 0; i < 26; i++) {
            if (first[i] == INT_MAX || last[i] == INT_MIN || first[i] >= last[i] - 1) {
                continue;
            }
            
            unordered_set<char> middleChars;
            for (int j = first[i] + 1; j < last[i]; j++) {
                middleChars.insert(s[j]);
            }
            result += middleChars.size();
        }
        
        return result;
    }
};