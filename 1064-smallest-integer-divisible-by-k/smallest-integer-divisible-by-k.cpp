class Solution {
public:
    int smallestRepunitDivByK(int k) {
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