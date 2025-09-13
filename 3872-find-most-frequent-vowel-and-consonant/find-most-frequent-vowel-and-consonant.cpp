class Solution {
public:
bool isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return true;
    }
    else
    {
        return false;
    }
}
    int maxFreqSum(string s) {
        map<char,int> vowel_frequency;
        map<char,int> consonant_frequency;
        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                vowel_frequency[s[i]]++;
            }
            else
            {
                consonant_frequency[s[i]]++;
            }
        }
        int vowel=0;
        int consonant=0;
        for(auto ch:vowel_frequency)
        {
            if(vowel<ch.second)
            {
                vowel=ch.second;
            }
        }
        for(auto ch:consonant_frequency)
        {
            if(consonant<ch.second)
            {
                consonant=ch.second;
            }
        }
        return vowel+consonant;
    }
};