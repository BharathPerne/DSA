// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int
//     k1,
//                                int k2) {
//         priority_queue<int> res;
//         for (int i = 0; i < nums1.size(); i++) {
//             res.push(abs(nums1[i] - nums2[i]));
//         }
//         long long sum = 0;
//         int reduce = k1 + k2;
//         while (reduce) {
//             int x = res.top();
//             res.pop();
//             int y = res.top();
//             int diff = x - y;
//             if (diff!=0&&diff <= reduce) {
//                 res.push(y);
//                 reduce -= diff;
//                 continue;
//             } else if (x != 0) {
//                 x--;
//             }
//             res.push(x);
//             reduce--;
//         }
//         while (res.size() > 0) {
//             long long x = res.top();
//             sum = sum + (x * x);
//             res.pop();
//         }
//         return sum;
//     }
// };
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps = min(countDiff[currDiff], K);

            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;
            K -= countOps;
        }

        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};
