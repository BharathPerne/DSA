class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0)
        {
            return "0";
        }
        string result;
        if(((long long)numerator*(long long)denominator<0))
        {
            result+="-";
        }
        long long absnumerator=labs(numerator);
        long long absdenominator=labs(denominator);
        result+=to_string(absnumerator/absdenominator);
        long long remain=absnumerator%absdenominator;
        if(remain==0)
        {
            return result;
        }
        result+=".";
        map<int,int> mp;
        while(remain!=0)
        {
            if(mp.count(remain))
            {
                result.insert(mp[remain],"(");
                result+=")";
                break;
            }
            mp[remain]=result.length();
            remain*=10;
            int digit=remain/absdenominator;
            result+=to_string(digit);
            remain=remain%absdenominator;
        }
        return result;
    }
};