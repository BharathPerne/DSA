class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {       
        for(int i=0;i<nums.size();i++){
            int max_ele=*max_element(nums.begin(),nums.begin()+i);
            int min_ele=*min_element(nums.begin()+i,nums.end());
            if((max_ele-min_ele)<=k){
                return i;
            }
        }
        return -1;
    }
};