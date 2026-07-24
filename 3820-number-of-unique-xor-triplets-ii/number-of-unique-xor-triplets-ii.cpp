class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> uniq(nums.begin(), nums.end());
        vector<int> vals(uniq.begin(), uniq.end());
        const int MAXX = 2048;
        vector<bool> pairXor(MAXX, false);
        for (int x : vals) {
            for (int y : vals) {
                pairXor[x ^ y] = true;
            }
        }
        vector<bool> ans(MAXX, false);
        for (int v = 0; v < MAXX; v++) {
            if (!pairXor[v]) continue;
            for (int x : vals) {
                ans[v ^ x] = true;
            }
        }
        int res = 0;
        for (bool x : ans)
            if (x) res++;
        return res;
    }
};