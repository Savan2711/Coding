#include<bits/stdc++.h>
using namespace std;

// #define cerr if(false)cerr
#define ll long long
void solve();

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("error.txt", "w", stderr);
//    freopen("output.txt", "w", stdout);
//    #endif


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void longestCommonSubsequence(string text1, string text2) {
        
    int l1 = text1.length(), l2 = text2.length();
    int dp[l1 + 1][l2 + 1];
    vector<char> ans;
        
    for(int i = 0; i <= l1; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= l2; i++)
    {
        dp[0][i] = 0;
    }
        
        
    for(int i = 1; i <= l1; i++)
    {
        for(int j = 1; j <= l2; j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }

    int i = l1, j = l2;


    while(i && j)
    {
        while(i && j && dp[i][j] == dp[i - 1][j])
        {i--;}
        if(i)
        {ans.push_back(text1[i - 1]);}
        i--;

        while(i && j && dp[i][j] == dp[i][j - 1])
        {j--;}
    }


	for(auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		cout << *it;
	}
//    for(int i = ans.size() - 1; i >= 0; i--)// = ans.rbegin(); it != ans.rend(); it--)
//    {
//        cout << ans[i];
//    }
	
    cout << endl;

    // return dp[l1][l2];
        
}

void solve() {
    
    string t1, t2;
    cin >> t1;
	cin >> t2;
    longestCommonSubsequence(t1, t2);

}


