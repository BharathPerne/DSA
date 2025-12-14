class Solution {
public:
    int numberOfWays(string corridor) {
        int prevIndex=0;
        int nextIndex=0;
        long long result=1;
        int index=0;
        int j=0;
        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i]=='S')
            {
                j=++i;
                break;
            }
        }
        bool flag=0;
        for(int i=j;i<corridor.size();i++)
        {
            if(corridor[i]=='S')
            {
                index++;
                nextIndex=i+1;
                if(index%2==0)
                {
                    if(nextIndex-prevIndex-flag<=0)
                    {
                        continue;
                    }
                    result*=(nextIndex-prevIndex);
                   result = result % 1000000007;
                    flag=1;
                    std::cout<<result<<endl;   
                }
                prevIndex=nextIndex;
            }
        }
        index++;
        if(index==2)
        {
            return true;
        }
        if(index%2!=0||index<2)
        {
            return false;
        }
        return result;
    }
};