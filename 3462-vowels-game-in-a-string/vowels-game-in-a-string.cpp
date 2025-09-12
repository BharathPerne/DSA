class Solution {
public:
bool isvowel(int ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return true;
    }
    return false;
}
    bool doesAliceWin(string s) {
        int left=0,right=s.length()-1;
        while(left<=right)
        {
            if(isvowel(s[left])||isvowel(s[right])) //vowel checking
            {
                return true;
            }
            left++;
            right--;
        }
        return false;
    }
};