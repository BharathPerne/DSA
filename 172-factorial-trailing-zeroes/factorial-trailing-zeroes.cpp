class Solution {
public:
    int trailingZeroes(int n) {
        int pow=5;
        int count=0;
        while(1)
        {
            if(n/pow>0)
            {
                count+=n/pow;
                pow=pow*5;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};