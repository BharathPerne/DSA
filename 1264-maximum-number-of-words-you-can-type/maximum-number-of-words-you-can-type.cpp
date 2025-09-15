class Solution {
public:
void solve(string str,string brokenLetters,int &result)
{
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<brokenLetters.size();j++)
        {
            if(str[i]==brokenLetters[j])
            {
                return;
            }
        }
    }
    result++;
}
    int canBeTypedWords(string text, string brokenLetters) {
        string str="";
        int result=0;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                solve(str,brokenLetters,result);
                str="";
            }
            str+=text[i];
        }
        solve(str,brokenLetters,result);
        return result;
    }
};