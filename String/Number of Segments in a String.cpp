/*
https://leetcode.com/problems/number-of-segments-in-a-string/
*/

class Solution {
public:
    int countSegments(string s) {
        
        int n = s.length(), ans = 0;
        
        int temp = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ') 
            {
                if(temp)
                {ans++;}
                temp = 0;
            }
            else
            {temp++;}
        }
        if(temp) ans++;
        return ans;
    }
};
