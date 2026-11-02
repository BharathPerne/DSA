class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;
        for (int i = 0; i < m - 1; i++) {
           string str=".";
            for (int j = 1; j < n; j++) {
                str+="#";
            }
             result.push_back(str);
        }
        string str="";
        for (int j = 0; j < n; j++) {
            str+=".";
        }
        result.push_back(str);
        return result;
    }
};