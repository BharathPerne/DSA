class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            if(!st.empty()&&st.top()==')'){
                st.pop();
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                //reverse(temp.begin(),temp.end());
                s.replace(i-temp.size()-1,temp.size()+2,temp);
                i=i-temp.size()-2;
            }
        }
        return s;
    }
};