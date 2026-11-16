class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
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
            // if (s != temp && s.size()==result.size()&& stoi(s) > stoi(result)) {
            //     break;
            // }
            s = result;
        }
        return s;
    }
};