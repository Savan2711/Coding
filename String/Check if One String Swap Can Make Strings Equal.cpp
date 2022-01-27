/*
https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int l1 = s1.length(), l2 = s2.length();
        if(l1 != l2) return false;
        
        int p1 = 0, p2 = 0, cnt = 0;
        for(int i = 0; i < l1; i++)
        {
            if(s1[i] != s2[i])
            {
                p2 = p1;
                p1 = i;
                cnt++;
            }
        }
        if(cnt ==  0) return true;
        if(cnt == 2 && (s1[p1] == s2[p2]) && (s1[p2] == s2[p1])) return true;
        return false;
    }
};
