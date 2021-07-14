/*
https://leetcode.com/problems/find-a-peak-element-ii/
*/

class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        int c, l = 0, h = n - 1;
        
        int mid;
        int maxi = INT_MIN, mInd;
        while(l + 2 <= h)
        {
            mid = h - (h - l) / 2;
            
            for(int i = 0; i < m; i++)
            {
                if(maxi < mat[i][mid])
                {
                    maxi = mat[i][mid];
                    mInd = i;
                }
            }
            
            if(mat[mInd][mid - 1] < mat[mInd][mid] && mat[mInd][mid] > mat[mInd][mid + 1])
            {
                ans.push_back(mInd);
                ans.push_back(mid);
                return ans;
            }
            
            if(mat[mInd][mid - 1] > mat[mInd][mid])
            {
                h = mid;
            }
            else
            {
                l = mid;
            }
            
        }
        
        maxi = INT_MIN, c = l;
        for(int i = 0; i < m; i++)
        {
            if(maxi < mat[i][l])
            {
                maxi = mat[i][l];
                mInd = i;
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(maxi < mat[i][h])
            {
                c = h;
                maxi = mat[i][h];
                mInd = i;
            }
        }
        
        ans.push_back(mInd);
        ans.push_back(c);
        return ans;
    }
};