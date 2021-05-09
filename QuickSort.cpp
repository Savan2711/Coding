/*
~~~~~~~~Quick Sort~~~~~~~

Input:
6
5 8 6 2 1 4

Output:
1 2 4 5 6 8
*/

#include<bits/stdc++.h>
using namespace std;

// #define cerr if(false)cerr
#define ll long long
void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif


	int t = 1;
  	// cin >> t;
  	while (t--) {
    	solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

void quicksort(vector<int> &arr, int lb, int ub)
{
	if(lb < ub)
	{
		int i = lb;
		int j = ub + 1;
		
		int pivot = arr[i];

		while(true)
		{
			i++;
			while(i <= ub && arr[i] < pivot) i++;
			
			j--;
			while(arr[j] > pivot) j--;

			if(i < j)
			{swap(arr[i], arr[j]);}
			else
			{break;}
		}

		swap(arr[lb], arr[j]);

		quicksort(arr, lb, j - 1);
		quicksort(arr, j + 1, ub);

	}
}

void solve() {
	
	int n;
	cin >> n;

	vector<int> arr(n, 0);

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quicksort(arr, 0, n - 1);

	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

}