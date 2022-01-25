/*
https://leetcode.com/problems/valid-mountain-array/
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int ln = arr.size();
        if(ln <= 2) return false;
        
        int flag = 0, up = 0;
        for(int i = 0; i < ln - 1; i++)
        {
            if(!flag)
            {
                if(arr[i] >= arr[i + 1]) flag = 1;
                else up = 1;
            }
            
            if(flag && arr[i] <= arr[i + 1]) 
            {
                return false;
            }
        }
        
        return flag && up;
        
    }
};
