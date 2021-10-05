/*
https://leetcode.com/problems/merge-sorted-array/
*/

class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        
        int p1 = m - 1, p2 = n - 1;
        for(int i = m + n - 1; i >= 0; i--)
        {
            
            if(p1 >= 0 && p2 >= 0)
            {
                
                if(num1[p1] <= num2[p2])
                {
                    // cout << "here1 ";
                    num1[i] = num2[p2];
                    p2--;
                }
                else
                {
                    // cout << "here2 ";
                    num1[i] = num1[p1];
                    p1--;
                }
            }
            else
            {
                if(p1 >= 0)
                {
                    num1[i] = num1[p1];
                    p1--;
                }
                else
                {
                    num1[i] = num2[p2];
                    p2--;
                }
            }
        }
        
    }
};