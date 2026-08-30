class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_ele=INT_MAX,max_ele=INT_MIN;
        int min_ans=INT_MAX,max_ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_ele){
                min_ans=i;
                min_ele=nums[i];
            }
            if(nums[i]>max_ele){
                max_ans=i;
                max_ele=nums[i];
            }
        }    
        //min(i+1,(int)nums.size()-i)
        int front=max(min_ans,max_ans)+1;
        int back=(int)nums.size()-min(min_ans,max_ans);

        min_ans=min(min_ans+1,(int)nums.size()-min_ans);
        max_ans=min(max_ans+1,(int)nums.size()-max_ans);
        int front_back=min_ans+max_ans;
        // if(front_back<front&&front_back<back){
        //     return front_back;
        // }else if(front<back){
        //     return front;
        // }else{
        //     return back;
        // }
        return min({front,back,front_back});
    }
};