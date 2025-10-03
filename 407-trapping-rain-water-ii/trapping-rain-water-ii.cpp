#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    heap.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        int maxHeight = 0;
        
        while (!heap.empty()) {
            vector<int> cell = heap.top();
            heap.pop();
            int h = cell[0], i = cell[1], j = cell[2];
            maxHeight = max(maxHeight, h);
            
            for (auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    
                    if (heightMap[ni][nj] < maxHeight) {
                        water += maxHeight - heightMap[ni][nj];
                    }
                    
                    heap.push({max(heightMap[ni][nj], maxHeight), ni, nj});
                }
            }
        }
        
        return water;
    }
};