#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// https://www.youtube.com/watch?v=PLpzng35N54
int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {

        int n, m;
        cin >> n >> m;

        vector<int>arr(n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<vector<ll>>dp(n + 1, vector<ll>(m + 2, 0));

        if (arr[0] == 0) for (int i = 1; i <= m; i++) dp[1][i] = 1;
        else dp[1][arr[0]] = 1;

        for (int i = 2; i <= n; i++) {
            if (arr[i - 1] == 0) {
                for (int j = 1; j <= m; j++) {
                    (dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) %= mod;
                }
            }
            else {
                int j = arr[i - 1];
                (dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) %= mod;
            }

        }
        ll ans = 0;

        for (int i = 0; i <= m; i++) (ans += dp[n][i]) %= mod;
        cout << ans << endl;
    }
    return 0;
}
