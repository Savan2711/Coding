/*
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
*/

class Solution {
public:
    int minOperations(string s) {
        
        int startZero = 0, startOne = 0, flag = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(!flag)
            {
                if(s[i] == '0') startOne++;
                else startZero++;
                flag = 1;
            }
            else
            {
                if(s[i] == '0') startZero++;
                else startOne++;
                flag = 0;
            }
        }
        
        return min(startZero, startOne);
        
    }
};

