/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

class Solution {
public:
    string reverseWords(string s) {
        
        int l = 0, h = s.length() - 1;
        
        while(l < h)
        {
            char temp = s[l];
            s[l] = s[h];
            s[h] = temp;
            l++;
            h--;
        }
        cout << s;
        
        string ans = "", temp = "";
        
        for(int i = 0; i < s.length(); i++)
        {
            temp += s[i];
            if(s[i] == ' ')
            {
                ans.insert(0, temp);
                temp = "";
            }
        }
        temp += ' ';  
        ans.insert(0, temp);
        ans.erase(s.length(), 1);
        return ans;
    }
};
