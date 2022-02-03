/*
https://leetcode.com/problems/decode-string/
*/

class Solution {
public:
    
    string repeat(string s, int n)
    {
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            ans += s;
        }
        return ans;
    }
    
    string function(string s, int &idx)
    {
        string substr = "";
        while(s[idx] >= 'a' && s[idx] <= 'z')
        {
            substr.push_back(s[idx]);
            idx++;
        }
        string digit = "";
        while(s[idx] >= '0' && s[idx] <= '9')
        {
            digit.push_back(s[idx]);
            idx++;
        }
        int num = 0;
        if(digit != "") num = stoi(digit);
        
        if(s[idx] == '[')
        {
            idx++;
            substr +=  repeat(function(s, idx), num);
        }
        else if(s[idx] == ']')
        {
            idx++;
            return substr;
        }
        while(idx < s.length() && s[idx] >= 'a' && s[idx] <= 'z')
        {
            substr.push_back(s[idx]);
            idx++;
        }
        if(idx >= s.length())
        {return substr;}
        else{
            substr += function(s, idx);
        }
        return substr;
    }
    
    string decodeString(string s) {
        
        int i = 0;
        return function(s, i);
        
    }
};
