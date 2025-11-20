#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        
        vector<int> nums;  
        int count = 0;
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            
            int pointsInInterval = 0;
            for (int num : nums) {
                if (num >= start && num <= end) {
                    pointsInInterval++;
                }
            }
            
            int needed = 2 - pointsInInterval;
            for (int i = 0; i < needed; i++) {
                int newPoint = end - i;
                while (find(nums.begin(), nums.end(), newPoint) != nums.end()) {
                    newPoint--;
                }
                nums.push_back(newPoint);
                count++;
            }
        }
        
        return count;
    }
};