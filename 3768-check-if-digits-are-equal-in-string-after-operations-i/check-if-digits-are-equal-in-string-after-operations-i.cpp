class Solution {
public:
    bool hasSameDigits(string s) {
        while(true)
        {
            if(s.size()==2&&s[0]==s[1])
            {
                return true;
            }
            else if(s.size()==2&&s[0]!=s[1])
            {
                return false;
            }
            for(int i=1;i<s.size();i++)
            {
                int sum=(s[i-1]+s[i])%10;
                s[i-1]=sum;
            }
            s.erase(s.size()-1);
        }
    }
};