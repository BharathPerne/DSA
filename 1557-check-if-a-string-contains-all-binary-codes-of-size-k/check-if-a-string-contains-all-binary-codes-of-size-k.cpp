class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // If the string length is less than k, impossible to have all codes
        if (s.length() < k) return false;
        
        unordered_set<string> codes;
        
        // Extract all substrings of length k
        for (int i = 0; i <= s.length() - k; i++) {
            codes.insert(s.substr(i, k));
        }
        
        // Check if we have all 2^k possible codes
        return codes.size() == (1 << k);
    }
};