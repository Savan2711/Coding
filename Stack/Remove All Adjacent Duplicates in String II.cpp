/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int ln = s.length();
        stack<pair<char, int>> st;
        
        for(int i = ln - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push(make_pair(s[i], 1));
            }
            else
            {
                if((st.top()).first != s[i])
                {
                    // cout << "here";
                    st.push(make_pair(s[i], 1));
                }
                else
                {
                    (st.top()).second++;
                }
                
                if((st.top()).second == k)
                {
                    st.pop();
                }
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += string((st.top()).second, (st.top()).first);
            st.pop();
        }
        
        return ans;
        
    }
};
