class Solution {
public:
    int numSub(string s) {
        vector<long long> res={0};
        long long result=0;
        long long index=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                result=(result+index)%(1000000007);
                index++;
            }
            else
            {
                result+=res[res.size()-1];
                res.push_back(result);
                result=0;
                index=1;
            }
        }
        if(s[s.size()-1]=='1')
        {
            result+=res[res.size()-1];
            res.push_back(result);
        }
        return res[res.size()-1];
    }
};