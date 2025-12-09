class Solution {
public:
    int titleToNumber(string columnTitle) {
        // int count=columnTitle[columnTitle.size()-1]-'A'+1;
        // for(int i=columnTitle.size()-2;i>=0;i--)
        // {
        //     count+=(columnTitle[i]-'A'+1)*26;
        // }
        // return count;
        
        int size=columnTitle.size()-1;
        int count=(columnTitle[0]-'A'+1)*pow(26,size);
        size--;
        for(int i=1;i<columnTitle.size();i++)
        {
            count+=(columnTitle[i]-'A'+1)*pow(26,size);
            size--;
        }
        return count;
    }
};