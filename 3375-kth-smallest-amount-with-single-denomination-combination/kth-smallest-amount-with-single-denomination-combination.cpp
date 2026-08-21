#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdll(long long a, long long b) {
        return b == 0 ? a : gcdll(b, a % b);
    }

    long long lcmLL(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }

    // Count how many positive integers <= x are divisible
    // by at least one coin.
    long long count(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    l = lcmLL(l, coins[i]);
                    // l > x means this subset contributes nothing.
                    if (l > x) {
                        overflow = true;
                        break;
                    }
                }
            }
            if (overflow)
                continue;
            long long cnt = x / l;
            // Odd-sized subset -> add
            // Even-sized subset -> subtract
            if (bits & 1)
                ans += cnt;
            else
                ans -= cnt;
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        // The answer cannot exceed k * minimum coin.
        long long mn = *min_element(coins.begin(), coins.end());
        long long lo = 1;
        long long hi = mn * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
