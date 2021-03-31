/*
To rearrange a array.
If we are given 1, 2, 3, 4, 5, 6 we have to mix it as 1, 4, 2, 5, 3, 6.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if(n > 2)
    {
        int fast = 1, slow = n / 2;
        
        while(fast != slow)
        {
            int temp = arr[slow];
            int i = slow - 1;
            while(i >= fast)
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[fast] = temp;
            fast += 2;
            slow += 1;
        }
        
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
	return 0;
}