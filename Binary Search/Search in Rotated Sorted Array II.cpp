/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    
    vector<int> input;
    int size, t;
    
    int searchMin(int low, int high)
    {
        if(input[0] < input[size - 1])
        {
            return 0;
        }
        
        int temp = -1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            //cout << low << " " << mid << " " << high << endl;
            
            if(input[mid] > input[0])
            {
                low = mid + 1;
               temp = mid;
            }
            else if(input[low] == input[0])
            {
                low += 1;
            }
            else 
            {
                high = mid;
            }
           
        }
        if(temp != -1 and temp < low)
        {
            low = temp + 1;
        }
        return low;
    }
    
    bool binarySearch(int low, int high)
    {
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(input[mid] == t)
            {
                return true;
            }
            else if(input[mid] > t)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        return false;
    }
    
    int search(vector<int>& nums, int target) {
        
        input = nums;
        size = nums.size();
        t = target;
    
        if(!size)
        {return false;}
        
        int minIndex = searchMin(0, size - 1);
        //cout << minIndex << " " << size << endl;
        return (binarySearch(0, minIndex - 1) || binarySearch(minIndex, size - 1));
     }
};
