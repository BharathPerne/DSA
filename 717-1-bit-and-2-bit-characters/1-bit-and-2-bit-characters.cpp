class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag=0;
        for(int i=0;i<bits.size();i++)
        {
            if(bits[i]==1)
            {
                i++;
                flag=0;
            }
            else
            {
                flag=1;
            }
        }
        return flag;
    }
};