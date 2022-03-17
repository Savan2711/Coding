/*
https://leetcode.com/problems/score-of-parentheses/
*/

class Solution {
public:
    int scoreOfParentheses(string S) {
       
        int n = S.length();
        
        stack<int> st;
        st.push(0);
        for(int i = 0; i < n; i++)
        {
            if(S[i] == '(')
            {
                st.push(0);
            }  
            else
            {
                int a1 = st.top();
                st.pop();
                int a2 = st.top(); 
                st.pop();
                a1 = a1 == 0 ? 1 << a1 : a1 << 1;
                st.push(a2 + a1);
            }
        }
        return st.top();
    }
};
