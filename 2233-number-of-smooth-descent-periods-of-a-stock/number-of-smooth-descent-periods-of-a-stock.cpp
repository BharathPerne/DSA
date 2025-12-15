class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long j=0;
        long long result=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i-1]>prices[i]&&prices[i-1]==(prices[i]+1))
            {
                result++;
                j+=result;
            }
            else
            {
                result=0;
            }
        }
        return j+prices.size();
    }
};