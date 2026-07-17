class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1, 0);
        for (int x : nums)
            cnt[x]++;

        vector<long long> divisible(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                divisible[d] += cnt[m];
        }

        // exact[g] = pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            exact[g] = divisible[g] * (divisible[g] - 1) / 2;

            for (int m = 2 * g; m <= mx; m += g)
                exact[g] -= exact[m];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (pref[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};