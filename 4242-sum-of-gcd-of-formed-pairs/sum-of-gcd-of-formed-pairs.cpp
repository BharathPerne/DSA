class Solution {
public:
int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
    long long gcdSum(vector<int>& nums) {
        vector<int> pre_gcd;
        int max_ele=0;
        for(int i=0;i<nums.size();i++){
            max_ele=max(max_ele,nums[i]);
            pre_gcd.push_back(gcd(max_ele,nums[i]));
        }
        sort(pre_gcd.begin(),pre_gcd.end());
        int l=0;
        int r=pre_gcd.size()-1;
        long long ans=0;
        while(l<r){
            ans+=gcd(pre_gcd[r],pre_gcd[l]);
            l++;
            r--;
        }
        return ans;
    }
};