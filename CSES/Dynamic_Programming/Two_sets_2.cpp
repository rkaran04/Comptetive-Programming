#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

ll num_ways(ll i, ll sum, vector<vector<ll>>&dp) {
    if (sum == 0) return 1;
    if (i == 0) return 0;
    if (dp[i][sum] != -1) return dp[i][sum] % mod;
    ll ans = 0;
    if (i <= sum) (ans += num_ways(i - 1, sum - i, dp)) %= mod;
    (ans += num_ways(i - 1, sum, dp)) %= mod;
    return (dp[i][sum] = ans ) %= mod;
}


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        ll n;
        cin >> n;

        ll sum = n * (n + 1);
        sum = sum / 2;
        if (sum % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        sum = sum / 2;
        // cout << sum << endl;
        vector<vector<ll>>dp(n + 1, vector<ll>(sum + 1, -1));

        cout << (num_ways(n, sum, dp) * 500000004) % mod << endl;

    }
    return 0;
}
