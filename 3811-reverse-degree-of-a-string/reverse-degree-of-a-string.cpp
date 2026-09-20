class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            result+=(26-(s[i]-'a'))*(i+1);
        }
        return result;
    }
};