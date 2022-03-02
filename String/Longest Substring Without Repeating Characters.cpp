/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/* Sliding window */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int low = 0, high = 0, ans = 0;
        set<char> st;
        
        while(high < s.length())
        {
            if(low == high)
            {
                st.insert(s[high]);
                high++;
            }
            else if(st.find(s[high]) != st.end())
            {
                st.erase(s[low]);
                low++;
            }
            else
            {
                st.insert(s[high]);
                high++;
            }
            if(ans < (high - low)) 
            {ans = high - low;}
        }
        if(ans < (s.length() - low)) ans = s.length() - low;
        return ans;
    }
};
