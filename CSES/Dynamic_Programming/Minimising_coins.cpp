#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {

        int n, x;
        cin >> n >> x;

        vector<int>coins(n);
        for (int i = 0; i < n; i++) cin >> coins[i];

        vector<int>dp(x + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= x; i++) {
            int ans = 1e9;
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) continue;
                if (dp[i - coins[j]] == 1e9) continue;
                ans = min(ans, 1 + dp[i - coins[j]]);
            }
            dp[i] = ans;
        }

        if (dp[x] == 1e9) cout << -1 << endl;
        else cout << dp[x] << endl;
    }
    return 0;
}
