class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();        
         
       int q = n / 8;
       int r = n % 8;

        return 8 * (q * (q + 1) / 2) + r * (q + 1);
    }
};