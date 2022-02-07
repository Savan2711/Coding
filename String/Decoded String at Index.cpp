/*
https://leetcode.com/problems/decoded-string-at-index/
*/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long int ln = 0;
        int i = 0;
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                ln *= s[i] - '0';
            }
            else 
            {
                ln++;
            }
        }
        // cout << ln;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            k %= ln;
            if(k == 0 && isalpha(s[i]))
            {return (string)"" + s[i];}
            else if(s[i] >= '0' && s[i] <= '9')
            {
                ln /= s[i] - '0';
            }
            else
            {ln--;}
        }
        return "";
        
    }
};
 
