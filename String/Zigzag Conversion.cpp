/*
https://leetcode.com/problems/zigzag-conversion/
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1 || numRows == s.length()) return s;
        
        string ans = "";
        int cnt;
        
        for(int i = 0; i < numRows; i++)
        {
            cnt = i;
            if(i == 0 || i == numRows - 1)
            {
                while(cnt < s.length())
                {
                    ans += s[cnt];
                    cnt += (2 * numRows) - 2;
                }
            }
            else
            {
                while(1)
                {
                    if(cnt < s.length()) ans += s[cnt];
                    else break;
                    
                    if(cnt + ((2 * numRows) - 2) -  (2 * i) < s.length()) 
                        ans += s[cnt + ((2 * numRows) - 2) -  (2 * i)];
                    else
                        break;
                    
                    cnt += (2 * numRows) - 2;
                }
            }
        }
        return ans;
    }
};
