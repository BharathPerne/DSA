class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vt(m,string(n,'#'));
        for(int i=0;i<n;i++){
            vt[0][i]='.';
        }
        for(int j=0;j<m;j++){
            vt[j][n-1]='.';
        }
        return vt;
    }
};