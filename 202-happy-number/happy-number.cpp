class Solution {
public:
    bool isHappy(int n) {
        string str=to_string(n);
        int i=0;
        while(i<=100)
        {
            if(str=="1")
            {
                return true;
            }
            int count=0;
            for(int i=0;i<str.size();i++)
            {
                int value=str[i]-'0';
                count+=(value*value);
            }
            str=to_string(count);
            i++;
        }
        return false;
    }
};