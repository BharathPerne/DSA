class Solution {
public:
    int smallestNumber(int n) {
        int ans=0,i=0;
        while(n)
        {
            ans+=pow(2,i);
            n=n/2;
            i++;
        }
        return ans;
    }
};