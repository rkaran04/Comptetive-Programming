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
        sort(coins.begin(), coins.end());
        vector<int>dp(x + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= x; i++) {

            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) break;
                (dp[i] += dp[i - coins[j]]) %= mod;
            }

        }

        cout << dp[x] << endl;
    }
    return 0;
}
