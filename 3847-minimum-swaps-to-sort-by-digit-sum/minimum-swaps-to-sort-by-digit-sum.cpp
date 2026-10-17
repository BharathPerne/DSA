class Solution {
public:
    int minSwaps(vector<int>& v)
    {
        int n=v.size();
        vector<int>tempv;
        tempv=v;
        unordered_map<long long,int>mp;
        for(int i=0;i<n;i++)
        mp[v[i]]=i;
        sort(tempv.begin(),tempv.end(),[](auto a,auto b)
        {
           int temp_a=a;
           int sum_a=0;
           while(temp_a>0)
           {
            sum_a=sum_a+temp_a%10;
            temp_a=temp_a/10;
           }
           int temp_b=b;
           int sum_b=0;
           while(temp_b>0)
           {
             sum_b=sum_b+temp_b%10;
             temp_b=temp_b/10;
           }
           if(sum_a==sum_b)
            return a<b;
           return sum_a<sum_b;
        });
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==tempv[i])
            continue;
            else
            {
                ans++;
                int j=mp[tempv[i]];
                swap(v[i],v[j]);
                mp[v[i]]=i;
                mp[v[j]]=j;
            } 
        }
      return ans;
    }
};