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
        string a;
        string b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++) dp[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ans = 0;
                ans = 1 + dp[i - 1][j];
                if (a[i - 1] == b[j - 1]) {
                    ans = min(ans, dp[i - 1][j - 1]);
                }
                else {
                    ans = min(ans, min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]));
                }
                dp[i][j] = ans;
            }
        }

        cout << dp[n][m] << endl;
    }
    return 0;
}
