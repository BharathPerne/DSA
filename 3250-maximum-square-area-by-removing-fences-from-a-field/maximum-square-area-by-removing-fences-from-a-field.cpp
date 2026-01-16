#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        
        // Step 1: collect all horizontal positions
        vector<int> hPos = hFences;
        hPos.push_back(1);
        hPos.push_back(m);
        sort(hPos.begin(), hPos.end());
        hPos.erase(unique(hPos.begin(), hPos.end()), hPos.end());
        
        // Step 2: collect all vertical positions
        vector<int> vPos = vFences;
        vPos.push_back(1);
        vPos.push_back(n);
        sort(vPos.begin(), vPos.end());
        vPos.erase(unique(vPos.begin(), vPos.end()), vPos.end());
        
        // Step 3: compute all horizontal gaps
        unordered_set<int> hGaps;
        for (int i = 0; i < hPos.size(); i++) {
            for (int j = i + 1; j < hPos.size(); j++) {
                hGaps.insert(hPos[j] - hPos[i]);
            }
        }
        
        // Step 4: compute all vertical gaps and find max common
        long long maxSide = -1;
        for (int i = 0; i < vPos.size(); i++) {
            for (int j = i + 1; j < vPos.size(); j++) {
                int gap = vPos[j] - vPos[i];
                if (hGaps.count(gap)) {
                    maxSide = max(maxSide, (long long)gap);
                }
            }
        }
        
        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % MOD;
    }
};