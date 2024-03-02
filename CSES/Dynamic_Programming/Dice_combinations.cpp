#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {

        int n;
        cin >> n;

        vector<ll>dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            ll ans = 0;
            for (int k = 1; k <= 6; k++) {
                if (i >= k) (ans = ans + dp[i - k]) %= mod;
            }
            dp[i] = ans;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
