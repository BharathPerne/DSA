class Solution {
public:
    int minFlips(string s) {
        int n = s.length();        
        string doubled = s + s;
                
        string target0 = "", target1 = "";
        for (int i = 0; i < 2 * n; i++) {
            target0 += (i % 2 == 0) ? '0' : '1';
            target1 += (i % 2 == 0) ? '1' : '0';
        }
                
        vector<int> prefix0(2 * n + 1, 0);
        vector<int> prefix1(2 * n + 1, 0);
        
        for (int i = 0; i < 2 * n; i++) {
            prefix0[i + 1] = prefix0[i] + (doubled[i] != target0[i] ? 1 : 0);
            prefix1[i + 1] = prefix1[i] + (doubled[i] != target1[i] ? 1 : 0);
        }
                
        int minFlips = n;
        for (int i = 0; i < n; i++) {
            int flips0 = prefix0[i + n] - prefix0[i];
            int flips1 = prefix1[i + n] - prefix1[i];
            minFlips = min({minFlips, flips0, flips1});
        }
        
        return minFlips;
    }
};