class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0)
        {
            return -1;
        }
        int current=0;
        for(int length=1;length<=k;length++)
        {
            current=((current*10)+1)%k;
            if(current==0)
            {
                return length;
            }
        }
        return -1;
    }
};