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

        vector<int>price(n);
        for (int i = 0; i < n; i++) cin >> price[i];

        vector<int>pages(n);
        for (int i = 0; i < n; i++) cin >> pages[i];

        vector<vector<int>>dp(n + 1, vector<int>(x + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                int ans = dp[i - 1][j];
                if (price[i - 1] <= j) ans = max(ans, pages[i - 1] + dp[i - 1][j - price[i - 1]]);
                dp[i][j] = ans;
            }
        }

        cout << dp[n][x] << endl;

    }
    return 0;
}
