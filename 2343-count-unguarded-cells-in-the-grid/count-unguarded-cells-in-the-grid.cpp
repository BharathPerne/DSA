#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (const auto& guard : guards) {
            int r = guard[0], c = guard[1];
            
            for (const auto& dir : directions) {
                int dr = dir.first, dc = dir.second;
                int nr = r + dr, nc = c + dc;
                
                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == 2 || grid[nr][nc] == 1) {
                        break;
                    }
                    
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 3;
                    }
                    nr += dr;
                    nc += dc;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};