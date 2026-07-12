class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
        vector<int> temp=arr;
        vector<int> ans;
         if(arr.size()==0){
            return ans;
        }
        if(arr.size()==1){
            ans.push_back(1);
            return ans;
        }
        map<int,int> result;       
        sort(temp.begin(),temp.end());        
        int rank=1;
        result[temp[0]]=rank;
        for(int i=1;i<temp.size();i++){
            if(temp[i-1]!=temp[i]){
                 rank++;
                result[temp[i]]=rank;               
            }else{
                 result[temp[i]]=rank;
            }
        }       
        for(int i=0;i<arr.size();i++){
            ans.push_back(result[arr[i]]);
        }
        return ans;
    }
};