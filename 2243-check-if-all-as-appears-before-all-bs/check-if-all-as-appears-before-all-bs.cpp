class Solution {
public:
    bool checkString(string s) {
        int is_a=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a'){
                is_a=true;
            }
            if(is_a&&s[i]=='b'){
                return false;
            }
        }
        return true;
    }
};