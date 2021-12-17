/*
https://leetcode.com/problems/add-binary/
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length() > b.length()) return addBinary(b, a);
        
        string temp = "", ans = "";
        for(int i = 0; i < (b.length() - a.length()); i++)
        {
            temp += '0';
        }
        
        a = temp + a;
        
        char carry = '0';
        // cout << a;
        for(int i = b.length() - 1; i >= 0; i--)
        {
            if(a[i] == '1' && b[i] == '1')
            {
                ans += carry;
                carry = '1';
            }
            else if(a[i] == '0' && b[i] == '0')
            {
                ans += carry;
                carry = '0';
            }
            else
            {
                if(carry == '1')
                {
                    ans += '0';
                }
                else
                {
                    ans += '1';
                }
            }
        }
        
        if(carry == '1')
        {
            ans += '1';
        }
        
        return string(ans.rbegin(), ans.rend());
        
    }
};    
