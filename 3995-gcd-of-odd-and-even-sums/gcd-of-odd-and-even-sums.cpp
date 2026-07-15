class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
        if(n==1){
            return 1;
        }
        int even_sum=0;
        int odd_sum=0;
        for(int i=1;i<=n*2;i++){
            odd_sum+=i;
            i++;
            even_sum+=i;
        }
        return even_sum%odd_sum;
    }
};