class Solution {
public:
    bool checkDivisibility(int n) {        
        int number=n;
        int digit_sum=0;
        int digit_product=1;
        while(n!=0){
            digit_sum+=(n%10);
            digit_product*=(n%10);
            n=n/10;
        }
        return number%(digit_sum+digit_product)==0;
    }
};