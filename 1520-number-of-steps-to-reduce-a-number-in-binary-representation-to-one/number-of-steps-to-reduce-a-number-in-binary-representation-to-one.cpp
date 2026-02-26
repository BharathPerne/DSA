class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while (s.length() > 1) {
            int n = s.length();
            
            if (s[n-1] == '0') {                
                s.pop_back();
                steps++;
            } else {                
                steps++;                                
                int i = n - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }                
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = "1" + s;
                }
            }
        }        
        return steps;
    }
};