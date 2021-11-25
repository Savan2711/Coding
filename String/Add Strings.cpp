/*
https://leetcode.com/problems/add-strings/
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
        // cout << nums1 << " " << nums2 << endl;;
        
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
};
