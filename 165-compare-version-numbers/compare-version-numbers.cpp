class Solution {
public:
int validate(string ver1,string ver2)
{
    if(stod(ver1)<stod(ver2))
        {
            return -1;
        }
        else if(stod(ver1)>stod(ver2))
        {
            return 1;
        }
        return 0;
}
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        // string v1,v2;
        // while(i<version1.length()&&version1[i]!='.')
        // {
        //     v1+=version1[i];
        //     i++;
        // }
        // while(j<version2.length()&&version2[j]!='.')
        // {
        //     v2+=version2[j];
        //     j++;
        // }
        // if(stoi(v1)<stoi(v2))
        // {
        //     return -1;
        // }
        // if(stoi(v1)>stoi(v2))
        // {
        //     return 1;
        // }
        string ver1="0",ver2="0";
        while(i<version1.length()||j<version2.length())
        {
            while(i<version1.length()&&version1[i]!='.')
            {
                ver1+=version1[i];
                i++;
            }
            while(j<version2.length()&&version2[j]!='.')
            {
                ver2+=version2[j];
                j++;
            }
            int val=validate(ver1,ver2);
            if(val==1||val==-1)
            {
                return val;
            }
            ver1="0";
            ver2="0";
            i++;
            j++;
        }
        // if(ver2=="")
        // {
        //     ver2=version2;
        //     ver1="";
        //      for(int i=0;i<version1.length();i++)
        //      {
        //         if(version1[i]=='.')
        //         {
        //             continue;
        //         }
        //         ver1+=version1[i];
        //      }
        // }
        // else if(ver1=="")
        // {
        //     ver1=version1;
        //     ver2=version2;
        // }
        // double num1=stod(version1);
        // double num2=stod(version2);
        return 0;
    }
};