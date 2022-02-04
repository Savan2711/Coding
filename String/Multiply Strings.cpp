/*
https://leetcode.com/problems/multiply-strings/
*/

class Solution {
public:
    
    string addStrings(string nums1, string nums2) {
        
        int l1 = nums1.length(), l2 = nums2.length();
        
        if(l1 < l2) return addStrings(nums2, nums1);
        
        int diff = l1 - l2;
        string temp = "";
        while(diff)
        {
            temp += '0';
            diff--;
        }
        
        nums2 = temp + nums2;
        
        int carry = 0, i = l1;
        string ans = "";
        while(i--)
        {
            int temp = (nums1[i] - '0') + (nums2[i] - '0') + carry;
            ans += to_string(temp % 10);
            carry = temp / 10;
            
        }
        
        if(carry) ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    string multiply(string nums1, string nums2) {
        
        int l1 = nums1.length(), l2 = nums2.length();
        
        if(l1 < l2) return multiply(nums2, nums1);
        
        string ans = "0", t2 = "";
        
        for(int i = l2 - 1; i >= 0; i--)    
        {
            
            int carry = 0;
            t2 = "";
            for(int j = l1 - 1; j >= 0; j--)
            {
                int temp = ((nums2[i] - '0') * (nums1[j] - '0') + carry);
                t2 += to_string(temp % 10);
                carry = temp / 10;
            }
            if(carry != 0)
            {t2 += to_string(carry);}
            reverse(t2.begin(), t2.end());
            t2.append(l2 - 1 - i, '0');
            ans = addStrings(ans, t2);
        }
        
        int i;
        for(i = 0; i < ans.length() - 1; i++)
        {
            if(ans[i] != '0')
            {break;}
        }
        return string(ans.begin() + i, ans.end());
    }
};
