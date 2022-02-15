/*
https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    vector<vector<string>> dp;
    
    Solution()
    {
        set<string> st;
        dp.push_back({""});
        dp.push_back({"()"});
        for(int i = 2; i < 9; i++)
        {
            for(auto s : dp[i- 1])
            {
                st.insert("(" + s + ")");
                st.insert(s + "()");
                st.insert("()" + s);
            }
            int l = 2, h = i - 2;
            while(l <= h)
            {
                for(auto s1 : dp[l])
                {
                    for(auto s2 : dp[h])
                    {
                        st.insert(s1 + s2);
                        st.insert(s2 + s1);
                    }
                }
                l++;
                h--;
            }
            vector<string> v(st.begin(), st.end());
            st.clear();
            dp.push_back(v);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        return dp[n];
        
    }
};




