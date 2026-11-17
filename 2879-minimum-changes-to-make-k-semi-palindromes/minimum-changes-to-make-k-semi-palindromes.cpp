
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;
                cost[i][j] = INT_MAX;

                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int r = 0; r < d; r++) {
                        for (int x = 0; x < len / d / 2; x++) {

                            int left = i + r + x * d;
                            int right = i + len - d + r - x * d;

                            if (s[left] != s[right])
                                changes++;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1,
            vector<int>(k + 1, INT_MAX));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= k; p++) {

                for (int len = 2; len <= i; len++) {

                    if (dp[i - len][p - 1] == INT_MAX)
                        continue;

                    dp[i][p] = min(dp[i][p],
                        dp[i - len][p - 1] +
                        cost[i - len][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
