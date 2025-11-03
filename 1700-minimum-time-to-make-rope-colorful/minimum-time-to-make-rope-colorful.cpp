// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int ans=0;
//         int index=1;
//         for(int i=1;i<colors.size();i++)
//         {
//             if(colors[i-1]==colors[i])
//             {
//                 if(neededTime[index-1]>neededTime[index])
//                 {
//                     ans+=neededTime[index];
//                     colors.erase(i,1);
//                     neededTime.erase(neededTime.begin()+index);
//                     i--;
//                 }
//                 else
//                 {
//                     ans+=neededTime[index-1];
//                     colors.erase(i-1,1);
//                     neededTime.erase(neededTime.begin()+index);
//                     i--;
//                 }
//             }
//             index++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        
        for (int i = 0; i < colors.size(); ) {
            int j = i;
            int maxTime = neededTime[i];
            int total = neededTime[i];
            
            // Find all consecutive same colors
            while (j + 1 < colors.size() && colors[j + 1] == colors[i]) {
                j++;
                maxTime = max(maxTime, neededTime[j]);
                total += neededTime[j];
            }
            
            // If we have consecutive balloons, remove all except the most expensive one
            if (j > i) {
                ans += total - maxTime;
            }
            
            i = j + 1;  // Move to next different color
        }
        
        return ans;
    }
};