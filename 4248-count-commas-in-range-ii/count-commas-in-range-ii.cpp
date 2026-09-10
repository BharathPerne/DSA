class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }
        long long ans=0;
        ans+=n-1000;
        ans+=1;
        if((n-1000000)>=0){
            ans+=n-1000000;
            ans+=1;
        }
        if((n-1000000000)>=0){
            ans+=n-1000000000;
            ans+=1;
        } 
        if((n-1000000000000)>=0){
            ans+=n-1000000000000;
            ans+=1;
        } 
        if((n-1000000000000000)>=0){
            ans+=n-1000000000000000;
            ans+=1;
        }   
        return ans;     
    }
};