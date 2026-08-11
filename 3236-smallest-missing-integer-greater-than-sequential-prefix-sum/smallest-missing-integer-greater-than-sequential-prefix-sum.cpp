class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seq_number=nums[0];
        map<int,int> num_count;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                seq_number+=nums[i];
            }else{
                break;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==seq_number){
                seq_number++;
            }
        }
        return seq_number;
    }
};