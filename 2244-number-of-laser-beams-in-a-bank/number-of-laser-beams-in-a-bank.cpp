class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0,curr=0,ans=0;
        for(int i=0;i<bank.size();i++)
        {
            int count=0;
            bool flag=1;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                {
                    flag=0;
                    count++;
                }
            }
            if(flag)
            {
                continue;
            }
            prev=curr;
            curr=count;
            ans+=prev*curr;
        }
        return ans;
    }
};