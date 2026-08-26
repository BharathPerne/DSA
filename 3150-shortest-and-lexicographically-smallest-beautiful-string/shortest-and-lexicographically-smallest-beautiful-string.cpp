class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0;
        int left = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                count++;
            }

            // We have more than k ones,
            // so move left until we have k ones again.
            while (count > k) {
                if (s[left] == '1') {
                    count--;
                }
                left++;
            }

            // Exactly k ones
            if (count == k) {

                // Remove unnecessary zeros from the left.
                while (s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};
