class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int result=0;
        int i=0;
        while(n){
            int number=n&1;
            result=result+(!number<<i);
            n=n>>1;
            i++;
        }
        return result;
    }
};