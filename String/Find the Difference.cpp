/*
https://leetcode.com/problems/find-the-difference/
*/

/* Straight forward solution using array of size 26 -> total lowercase laters */
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int ch[26] = {0};
        for(int i = 0; i <  s.length(); i++)
        {
            ch[s[i] - 'a']++;
        }
        
        for(int i = 0; i <  t.length(); i++)
        {
            ch[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(ch[i] != 0) return ('a' + i);
        }
        return 'a';
        
    }
};

/* Solution using XOR */
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int ln = s.size();
        char ans = t[ln];
        for(int i = 0; i < ln; i++)
        {
            ans = ans ^ (s[i] ^ t[i]);
        }
        return ans;
    
    }
};

