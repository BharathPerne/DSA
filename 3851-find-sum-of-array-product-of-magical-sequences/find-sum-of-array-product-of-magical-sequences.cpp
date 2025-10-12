class Solution {
public:
    int MOD = 1000000007;
    
    long long modPow(long long a, long long e) {
        long long res = 1;
        a %= MOD;
        while (e > 0) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }
    
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        
        // Precompute factorials and inverse factorials
        vector<long long> fact(m + 1), invFact(m + 1);
        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[m] = modPow(fact[m], MOD - 2);
        for (int i = m - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
        
        // Memoization cache: (mask, remaining_m, remaining_k, index) -> result
        map<tuple<long long, int, int, int>, long long> memo;
        
        function<long long(long long, int, int, int)> dfs = [&](long long mask, int rem_m, int rem_k, int idx) -> long long {
            if (rem_m == 0) {
                return (__builtin_popcountll(mask) == rem_k) ? 1 : 0;
            }
            if (idx == n) return 0;
            
            auto key = make_tuple(mask, rem_m, rem_k, idx);
            if (memo.count(key)) return memo[key];
            
            long long res = 0;
            
            // Try choosing 0 to rem_m copies of nums[idx]
            for (int cnt = 0; cnt <= rem_m; cnt++) {
                long long new_mask = mask + cnt;
                int new_rem_k = rem_k - (new_mask & 1);
                if (new_rem_k < 0) continue;
                
                // Number of ways to choose positions: C(rem_m, cnt)
                // Contribution: nums[idx]^cnt
                long long ways = fact[rem_m] * invFact[cnt] % MOD * invFact[rem_m - cnt] % MOD;
                long long product_power = modPow(nums[idx], cnt);
                
                long long next = dfs(new_mask >> 1, rem_m - cnt, new_rem_k, idx + 1);
                
                res = (res + ways * product_power % MOD * next % MOD) % MOD;
            }
            
            return memo[key] = res;
        };
        
        return dfs(0, m, k, 0);
    }
};