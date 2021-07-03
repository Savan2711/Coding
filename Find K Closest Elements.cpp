/*
https://leetcode.com/problems/find-k-closest-elements/
*/

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int target, int l, int h)
    {
        
        int left = 0, right = h;
        while (left + 1 < right){
            
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if(nums[left] <= target) return left;
        if(nums[right] == target) return right;
        return -1;
        
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        
        if(x < arr[0])
        {
            for(int i = 0; i < k; i++)
            {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        if(x > arr[arr.size() - 1])
        {
            for(int i = arr.size() - k; i < arr.size(); i++)
            {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        
        int lind =  binarySearch(arr, x, 0, arr.size() - 1);
        int rind = lind + 1;
        while(k)
        {
            int l = INT_MAX, r = INT_MAX;
            if(lind >= 0)
            {
                l = abs(arr[lind] - x); 
            }
            if(rind < arr.size())
            {
                r = abs(arr[rind] - x);
            }
            
            // cout << l << " " << r << endl;
            
            if(l <= r)
            {
                ans.push_back(arr[lind]);
                lind--;
            }
            else
            {
                ans.push_back(arr[rind]);
                rind++;
            }
            
            k--;
            
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};