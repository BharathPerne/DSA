class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
        {
            return {1};
        }
        vector<int> prev;
        prev.push_back(1);
        prev.push_back(1);
        
        for(int i=1;i<rowIndex;i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int j=1;j<prev.size();j++)
            {
                curr.push_back(prev[j-1]+prev[j]);
            }
            curr.push_back(1);
            prev=curr;
            // curr.empty();
        }
        return prev;
    }
};