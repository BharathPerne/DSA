class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string result = "";
            int ans = 0;
            for (int i = 0; i < s.size(); i++) {
                ans = ans + (s[i] - '0');
                if ((i + 1) % k == 0) {
                    result += to_string(ans);
                    ans = 0;
                }
            }
            if (s.size() % k != 0)
                result += to_string(ans);          
            s = result;
        }
        return s;
    }
};