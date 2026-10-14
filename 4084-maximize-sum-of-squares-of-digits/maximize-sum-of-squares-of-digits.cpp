class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result="";
        for(int it=0;it<num;it++){
            for(int i=9;i>=0;i--){
                if(sum>=i){
                    result+=to_string(i);
                    sum=sum-i;
                    break;
                }
            }
        }
        return sum==0 ? result: "";
    }
};