/*
https://leetcode.com/problems/reverse-string/
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
       
        int l = 0, h = s.size() - 1;
        
        while(l < h)
        {
            char tmp = s[l];
            s[l] = s[h];
            s[h] = tmp;
            l++;
            h--;
        }
        
    }
};
