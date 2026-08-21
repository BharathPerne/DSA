class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        // int gap;                  
        // gap=10*(reservedSeats[0][0]-1)+reservedSeats[0][1]-1;        
        // int ans=0;
        //  ans+=(gap/4);
        // for(int i=1;i<reservedSeats.size();i++){  
        //     int gap1=0; 
        //     if(reservedSeats[i-1][0]==reservedSeats[i][0]){                                   
        //          gap1=10*(reservedSeats[i][0]-1)+reservedSeats[i][1]-1;      
        //          if(reservedSeats[i-1][1])                                          
        //          ans+=((gap1-gap)/4);
        //          gap=gap1;
        //     }else{
        //         gap1=10*(reservedSeats[i][0]-1)+reservedSeats[i][1]-1;
        //         ans+=((gap1-gap)/4);
        //         gap=gap1;
        //     }
        // }
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col == 2 || col == 3 || col == 4 || col == 5)
                mp[row] |= 1; // left

            if (col == 4 || col == 5 || col == 6 || col == 7)
                mp[row] |= 2; // middle

            if (col == 6 || col == 7 || col == 8 || col == 9)
                mp[row] |= 4; // right
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            if (mask == 0)
                ans += 2;
            else if (mask == 1 || mask == 4 || mask == 2)
                ans += 1;
            else if (mask == 3 || mask == 6 || mask == 5)
                ans += 1;
            // mask == 7 → 0
        }

        return ans;
    }
};