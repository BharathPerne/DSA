class Solution {
public:
    int smallestNumber(int n) {
        // int ans=0,i=0;
        // while(n)
        // {
        //     ans+=pow(2,i);
        //     n=n/2;
        //     i++;
        // }
        // return ans;
        if(n==1)
        {
            return 1;
        }
        for(int i=1;i<n;i++)
        {
            if(pow(2,i)-1>=n)
            {
                return pow(2,i)-1;
            }
        }
        return false;
    }
};