class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                float fl=sqrt((i*i+j*j));
                int in=fl;
                if((fl-in)==0)
                {
                int c=sqrt((i*i+j*j));
                if(c!=i&&c!=j&&c>=1&&c<=n)
                {
                    count++;
                }
                }
                
            }
        }
        return count*2;
    }
};