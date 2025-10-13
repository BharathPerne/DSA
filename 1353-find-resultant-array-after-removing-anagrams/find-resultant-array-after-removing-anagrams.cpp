class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            sort(str.begin(),str.end());
            for(int j=i+1;j<words.size();j++)
            {
                string s=words[j];
                sort(s.begin(),s.end());
                if(s==str)
                {
                    words.erase(words.begin()+j);
                    j--;
                }
                else
                {
                    break;
                }
            }
        }
        return words;
    }
};