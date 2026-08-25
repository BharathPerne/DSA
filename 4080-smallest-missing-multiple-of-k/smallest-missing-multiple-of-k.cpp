class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if((k*(multiple))==nums[i]){
                multiple++;
            }
        }
        return k*multiple;
    }
};