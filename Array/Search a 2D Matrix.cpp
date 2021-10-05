/*
https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int l = 0, h = matrix.size() - 1, cInd = matrix[0].size() - 1, mid;
        
        while(l <= h)
        {
            mid = l + (h - l) / 2;
            
            if(matrix[mid][cInd] == target) return true;
            
            if(matrix[mid][0] <= target && matrix[mid][cInd] > target) break;
            
            if(matrix[mid][cInd] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // cout << mid << endl;
        int rMid;
        l = 0, h = cInd;
        while(l <= h)
        {
            rMid = l + (h - l) / 2;
            
            if(matrix[mid][rMid] == target) return true;
            
            if(matrix[mid][rMid] > target)
            {
                h = rMid - 1;
            }
            else
            {
                l = rMid + 1;
            }
        }
        return false;
    }
};