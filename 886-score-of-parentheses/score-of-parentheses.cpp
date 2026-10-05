class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(-1);
            }
            else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else {
                    int ans = 0;
                    while (st.top() != -1) {
                        ans += st.top();
                        st.pop();
                    }

                    st.pop();
                    st.push(2 * ans);
                }
            }
        }

        int result = 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};