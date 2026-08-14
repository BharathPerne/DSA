class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0,ans=0;
        map<int,int> s_count;
        for(int i=0;i<s.size();i++){
            s_count[s[i]]++;
            while(s_count[s[i]]>2){
                s_count[s[left]]--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};