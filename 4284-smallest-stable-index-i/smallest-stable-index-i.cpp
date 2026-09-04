class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        int diff=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int max_ele=*max_element(nums.begin(),nums.begin()+i);
            int min_ele=*min_element(nums.begin()+i,nums.end());
            if((max_ele-min_ele)<=k&&(max_ele-min_ele)!=diff){
                diff=max_ele-min_ele;
                ans=i;
                return i;
            }
        }
        return ans;
    }
};