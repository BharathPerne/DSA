class Solution {
public:

    bool check(string &s1, string &s2, string &s3,
               int i, int s2_index, int s3_index,
               vector<vector<int>>& dp) {

        if (s3_index == s3.size()) {
            return true;
        }

        if (dp[i][s2_index] != -1) {
            return dp[i][s2_index];
        }

        // Take from s1
        if (i < s1.size() &&
            s1[i] == s3[s3_index]) {

            if (check(s1, s2, s3,
                      i + 1, s2_index, s3_index + 1, dp)) {

                return dp[i][s2_index] = true;
            }
        }

        // Take from s2
        if (s2_index < s2.size() &&
            s2[s2_index] == s3[s3_index]) {

            if (check(s1, s2, s3,
                      i, s2_index + 1, s3_index + 1, dp)) {

                return dp[i][s2_index] = true;
            }
        }

        return dp[i][s2_index] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return check(s1, s2, s3, 0, 0, 0, dp);
    }
};