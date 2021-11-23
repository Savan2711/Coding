/*
https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

class Solution {
public:
    string reverseVowels(string s) {
        
        int l = 0, h = s.length() - 1;
        while(l < h)
        {
            if((s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' || s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U' ) && (s[h] == 'a' || s[h] == 'e' || s[h] == 'i' || s[h] == 'o' || s[h] == 'u' || s[h] == 'A' || s[h] == 'E' || s[h] == 'I' || s[h] == 'O' || s[h] == 'U'))
            {
                char temp;
                temp = s[l];
                s[l] = s[h];
                s[h] = temp;
                l++;
                h--;
            }
            else if(!(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') && !(s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U'))
            {
                l++;           
            }
            else if(!(s[h] == 'a' || s[h] == 'e' || s[h] == 'i' || s[h] == 'o' || s[h] == 'u') && !(s[h] == 'A' || s[h] == 'E' || s[h] == 'I' || s[h] == 'O' || s[h] == 'U'))
            {
                h--;
            }
        }
        return s;
    }        
};
