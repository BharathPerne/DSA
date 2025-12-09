class Solution {
public:
    int titleToNumber(string columnTitle) {
        // int count=columnTitle[columnTitle.size()-1]-'A'+1;
        // for(int i=columnTitle.size()-2;i>=0;i--)
        // {
        //     count+=(columnTitle[i]-'A'+1)*26;
        // }
        // return count;
        
        int count=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            count+=(columnTitle[i]-'A'+1)*pow(26,columnTitle.size()-i-1);
            
        }
        return count;
    }
};