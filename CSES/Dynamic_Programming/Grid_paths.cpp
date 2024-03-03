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

        int n;
        cin >> n;

        vector<vector<char>>grid(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, 0));


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1] == '*') continue;
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                (dp[i][j] = dp[i][j - 1] + dp[i - 1][j]) %= mod;
            }
        }

        cout << dp[n][n] << endl;

    }
    return 0;
}
