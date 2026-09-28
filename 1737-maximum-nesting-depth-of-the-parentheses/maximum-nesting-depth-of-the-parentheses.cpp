class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                result++;
            }else if(s[i]==')'){
                ans=max(result,ans);
                result--;
            }
        }
        return ans;
    }
};