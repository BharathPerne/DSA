class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        int index=0;
        for(int i=nums[0];i<nums[nums.size()-1];i++){
            if(nums[index]==i){
                index++;
            }else{
                result.push_back(i);               
            }
        }
        return result;
    }
};