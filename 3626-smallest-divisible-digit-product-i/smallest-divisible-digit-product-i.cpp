class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for (int i = n; i < i + t; i++) {
            int val=i;
            int product = 1;
            while (val != 0) {
                int num =val % 10;
                product *= num;
                val = val / 10;
            }                        
            if(product%t==0){
                return i;
            }
        }
        return -1;
    }
};