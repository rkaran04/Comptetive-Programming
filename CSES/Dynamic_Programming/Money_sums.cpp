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

        vector<int>coins(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
            sum += coins[i];
        }
        // sort(coins.begin(), coins.end());
        vector<vector<int>>dp(sum + 1, vector<int>(n + 1, 0) );
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        int total = 0;
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] || dp[i][j];
                if (dp[i][j]) continue;
                if (coins[j - 1] <= i) dp[i][j] = dp[i][j] || dp[i - coins[j - 1]][j - 1];
                if (dp[i][j]) continue;
            }
            if (dp[i][n]) total++;
        }
        cout << total << endl;
        for (int i = 1; i < sum; i++) if (dp[i][n])cout << i << " ";
        cout << sum << endl;
    }
    return 0;
}
