class Solution {
public:
    int totalMoney(int n) {
        int count=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i%7==0)
            {
                ans+=7+count;
                count=i/7;
                continue;
            }
            ans+=count+i%7;
        }
        return ans;
    }
};