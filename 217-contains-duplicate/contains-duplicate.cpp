class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int,int> m;
        // for(int i=0;i<nums.size();i++){
        //     if(m.find(nums[i])!=m.end()){
        //         return true;                
        //     }else{
        //         m[nums[i]]=1;
        //     }
        // }
        // return false;
         set<int> s(nums.begin(), nums.end());
         return s.size()!=nums.size();
    }
};