#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007



// think in terms of ways of making a new layer given the below layer has distinct blocks or same. in the code 0-->joined blocks
// 1-->separate blocks. If we want this layer to be separate, we can make this by some combination on top of separate and joined bottom 
// ḷayer. 
 
int main()
{

// entire dp is pre-computed here before taking in test cases
    vector<vector<ll>>dp(1e6 + 1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
 
    for (ll i = 2; i <= 1e6; i++) {
        (dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1]) %= mod; //joined new layer
        (dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][0]) %= mod; //separate new layer
    }
 
    int t ;
    cin >> t;
    // t = 1;
    for (int T = 0; T < t; T++) {
        ll n;
        cin >> n;
 
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
    return 0;
